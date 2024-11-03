#!/usr/bin/python3
# -*- coding: utf-8 -*-
"""
Created on Sun Oct 27 08:13:08 2024
 new version: self-discharge fitting
@author: Ariana
"""

import numpy as np
from scipy.special import gamma
import matplotlib.pyplot as plt
from scipy.optimize import minimize



class ML:       # Mittag-Leffer
    def __init__(self, alpha, a, b):
        self.N = 200   # accuracy
        self.a = a      
        self.b = b     
        self.alpha = alpha
      
    def Get(self, t):
        tmp = 0.0
        bt = -self.b * t**self.alpha
        tn = 1
        
        for nu in range(self.N):
            tmp += tn / gamma(nu * self.alpha + 1)
            tn *= bt
            
        return self.a * tmp


""" array SDG

class SDG:  # self discharge
    def __init__(self, alpha, t, lamda, v0, step):
        self.t = t  # t is expected to be a 1D array
        self.alpha = alpha
        self.lamda = lamda
        self.step = step
        self.F0 = v0
        self.E = [ML(self.alpha, ti) for ti in self.t]  # Calculate E for each element in t

    def solve(self):
        _F = [self.F0 * ei * (1 * self.lamda) * ((self.step * ti) ** (-self.alpha)) for ei, ti in zip(self.E, self.t)]
        return _F
"""



class SDG:      # self discharge
    def __init__(self, alpha, a, b, v0):
        self.t = t
        self.alpha = alpha
        self.a= a
        self.b  = b
        self.step = step
      #  self.E = ML(self.alpha,self.t)
        self.F0 = v0
        self.E = ML(self.alpha,self.a,self.b)

    def solve(self, t):
        _F = self.E.Get(t) +self.F0
        return _F



# initial guess
alpha=1
a=4.2
b=0.02
v0=4.2


# load data
data=np.loadtxt("b7-selfdischarge.txt")

"""
data[:,0] = 30*data[:,0]
voltage = data[:,1]
N=len(data)
step=(data[len(data)-1,0]-data[0,0])/(N-1)
#t_int=np.arange(data[0,0],data[len(data)-1,0],step)
t_int=np.arange(data[0,0],data[30,0],step)
"""
t = data[:,0]
voltage = data[:,1]
step = 30
"""
v = np.zeros(len(voltage))
v[0] = voltage [0]
for i in range(1,len(t)):
    
    selfdischarge = SDG(alpha, t[i], lamda, voltage[0], step)
    v[i] = selfdischarge.solve()
"""

#plt.plot(data[:,0],data[:,1], marker='4')

#plt.plot(t_int,v, marker='1')

def objective_function(params):
    
    alpha, a, b, v0 = params
    
    if any(param <= 0 for param in params):
        return float('inf')
    if alpha > 1 :
        return float('inf')
    
    v = np.zeros(len(voltage))
    v[0] = voltage [0]
    for i in range(1,len(t)):
        
        selfdischarge = SDG(params[0], params[1], params[2], params[3])
        v[i] = selfdischarge.solve(i)

    err=(sum((voltage[:]-v[:])**2))**0.5
    
    return err


initial_guess = [alpha, a, b, v0]
result = minimize(objective_function, initial_guess, method='Nelder-Mead')

optimal_params = result.x
print("Optimal Parameters:", optimal_params)

params_opt = optimal_params


v_opt = np.zeros(len(voltage))
v_opt[0] = voltage [0]
for i in range(1,len(t)):
    
    selfdischarge = SDG(params_opt[0], params_opt[1], params_opt[2], params_opt[3])
    v_opt[i] = selfdischarge.solve(i)


plt.plot(t,v_opt, marker='1')
plt.plot(data[:,0],data[:,1], marker='4')
#plt.yscale('log')
#plt.xscale('log')
plt.savefig('plot.pdf')
plt.show()





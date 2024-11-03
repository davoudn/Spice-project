#!/usr/bin/python3
import numpy as np
import csv
import numpy as np
from scipy.optimize import minimize
import matplotlib.pyplot as plt
import matplotlib


class EPotFit:
    def __init__(self,file, Skip):
        self.f = open(file)
        self.Skip = Skip
        self.data = self.GetEPotFromFile2()
        self.N =  len(self.data)
        self._N = self.N
        self.Suffix = file
        
    def EPot(self,t,p):
        return p[0] - p[1]*np.log(p[2]+t) - p[3] * np.sqrt(t) - p[4] * np.exp(-p[5]*t)
        
    def EPotDecomposition(self,t,p, sw):
        if sw == 0:
           return p[0] - p[1]*np.log(p[2] + t) - p[3] * np.sqrt(t) - p[4] * np.exp(-p[5]*t)
        if sw == 1:
           return -p[1]*np.log(p[2]+t)
        if sw == 2:
           return -p[3] * np.sqrt(t)
        if sw == 3:
           return -p[4] * np.exp(-p[5]*t)
        
        

    def ToSeconds(self,time):
#        print ( time.split(":") )
        return  float(time.split(":")[0]) * 3600 + float(time.split(":")[1]) * 60 + float(time.split(":")[2])


    def GetEPotFromFile(self):
        i=0
        data = []
        with self.f as csvfile:
            spamreader = csv.reader(csvfile, delimiter=',', quotechar='|')
            for row in spamreader:
                if (row[4] == "Rest"):
                       data.append([self.ToSeconds(row[5]),float(row[8])])
        return np.array(data)

    def GetEPotFromFile2(self):
        data=np.loadtxt("b7-selfdischarge-original.txt")

        return data


    def GetData(self):
        return self.data

    def ObjectiveFuncation(self,p):
        tmp=0
        count=0
        for i in range(0,self._N, self.Skip):
            tmp+= (self.EPot(self.data[i][0],p) - self.data[i][1] ) ** 2.0
            count+=1
        return np.sqrt(tmp)/count
        
    def ObjectiveInitialFit(self,p):
        tmp=0
        count=0
        for i in range(0,self._N):
            tmp+= (self.EPot(self.data[i][0],p) - self.data[i][1] ) ** 2.0
            count+=1
        return np.sqrt(tmp)/count
    
    def Fit(self, p0, iters = 1, ninitial = 10):
       self._N  = iters
       print ("Initial Optimization , self.N {N}".format(N=self._N))
       _p0 = minimize(self.ObjectiveInitialFit , p0, method='CG', options={'xatol': 1e-8, 'disp': True}).x
       print (_p0)
       print ("!--------------------------------------------------------------------------!")
    
       _step = self.N/iters
       for i in range(iters):
           self._N = int(_step * (i+1))
           print ("Iteration {i} , self.N {N}".format(i=i,N=self._N))
           _p0 = minimize(self.ObjectiveFuncation, _p0, method='CG', options={'xatol': 1e-8, 'disp': True}).x
           print (_p0)
           print ("!--------------------------------------------------------------------------!")
       import json
       jsonf = open("fitparameters{a0}.json".format(a0=self.Suffix), "w")
       _p0 = _p0.tolist()
       jsonp0 = json.dump(_p0, jsonf)
       
       return _p0

    def Plot(self,p0):
       styles = [{'linestyle':'solid','marker':"o",'markersize':1.0,'markeredgecolor':'blue','color':'blue'},{'linestyle':'solid','marker':"*",'markersize':1.0,'markeredgecolor':'red','color':'red'},
            {'linestyle':'solid','marker':"d",'markersize':1.0,'markeredgecolor':'green','color':'green'}, {'linestyle':'solid','marker':"s",'markersize':1.0,'markeredgecolor':'cyan','color':'cyan'},
            {'linestyle':'solid','marker':"p",'markersize':1.0,'markeredgecolor':'black','color':'black'}]
       # plot the data
#      matplotlib.use( 'tkagg' )
       fig = plt.figure()
       ax = fig.add_subplot(1, 1, 1)
       ax.plot(self.data[:,0], self.data[:,1],linewidth=4, color='tab:blue')
       for i in range(1): 
          ax.plot(self.data[:,0], self.EPotDecomposition(self.data[:,0],p0,i), linestyle=styles[i]['linestyle'],marker=styles[i]['marker'],markersize=styles[i]['markersize'],markeredgecolor=styles[i]['markeredgecolor'],   color=styles[i]['color'])
       plt.legend(('Raw Data', 'Fitted Curve', 'Faradic', 'Diffuse', 'Ohmic'), loc='upper right')
#      plt.show()
       fig.savefig('plot_{p0}.pdf'.format(p0=self.Suffix))
  
  
  
  
import sys, getopt, os.path
def main(argv):
    
  opts, args = getopt.getopt(argv,"hi:o:",["ifile=", "nskip=", "niter=", "ninitial="])
  nskip = 1
  niter = 1
  for opt, arg in opts:
       if opt == '--ifile':
          infile = arg
    
       if opt == '--nskip':
          nskip = int(arg)
          
       if opt == '--niter':
          niter = int(arg)
         
       if opt == '--ninitial':
          ninitial = int(arg)
          
  
  potfit = EPotFit(infile, nskip)
  p0 = [1.0,1.0,1.0,1.0,1.0,1.0]
  _p0 = potfit.Fit(p0,niter)
  potfit.Plot(_p0)  

if __name__ == "__main__":
   main(sys.argv[1:])


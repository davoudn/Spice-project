# SPICE Circuit Solver - Class Hierarchy

## Overview
This is a C++ SPICE circuit solver that uses numerical integration methods to solve circuit equations. The design follows an object-oriented approach with component abstraction and template-based integration methods.

---

## Class Hierarchy Diagram

```
                            ┌─────────────────────────────────────┐
                            │           BaseCircuit               │
                            │  (Circuit solving orchestration)   │
                            └─────────────────────────────────────┘
                                              │
                                              │ manages
                                              ▼
                            ┌─────────────────────────────────────┐
                            │         BaseComponent              │
                            │     (Abstract base class)         │
                            └─────────────────────────────────────┘
                                  │
              ┌───────────────────┴───────────────────┐
              │                                       │
              ▼                                       ▼
    ┌─────────────────────┐               ┌─────────────────────┐
    │    Resistor         │               │   ComplexComponent  │
    │ (Basic Component)   │               │  (Composite Model)  │
    └─────────────────────┘               └─────────────────────┘
                                                   │
                              ┌────────────────────┼────────────────────┐
                              │                    │                    │
                              ▼                    ▼                    ▼
                    ┌─────────────────┐  ┌─────────────────┐  ┌─────────────────┐
                    │ Capacitor<T>    │  │    CPE<T>       │  │ (Other complex) │
                    │ (Template)      │  │ (Template)      │  │                 │
                    └─────────────────┘  └─────────────────┘  └─────────────────┘
                              │                    │
                              └──────────┬──────────┘
                                         ▼
                              ┌─────────────────────┐
                              │  Resistor (eq)      │
                              │  CurrentSource (cs) │
                              └─────────────────────┘
```

---

## Detailed Class Descriptions

### 1. Core Infrastructure

#### [`BaseCircuit`](components/Circuit.hpp)
- **Purpose**: Main circuit solver class that orchestrates the solving process
- **Key Responsibilities**:
  - Initialize circuit from component parameters
  - Build system matrix (MNA - Modified Nodal Analysis)
  - Solve circuit equations using numerical integration
- **Key Members**:
  - `A` - System matrix (arma::Mat<double>)
  - `Z` - Right-hand side vector
  - `X` - Solution vector
  - `Components` - Vector of all circuit components

---

### 2. Component Hierarchy

#### [`BaseComponent`](components/BaseComponent.hpp) - Abstract Base Class
- **Purpose**: Base class for all circuit components
- **Key Members**:
  - `pos_net`, `neg_net` - Positive and negative node indices
  - `type`, `name` - Component identification
  - `voltages`, `currents` - History of voltages and currents
  - `i_eq`, `g_eq` - Equivalent current and conductance for linearization
  - `del_tau` - Time step
- **Virtual Methods**:
  - `Populate(double dv)` - Fill system matrix entries

---

#### [`Resistor`](components/Resistor.hpp) - Basic Component
- **Inheritance**: `BaseComponent`
- **ComponentClass**: `Basic`
- **Purpose**: Models a simple resistor
- **Key Members**:
  - `g` - Conductance (1/R)

---

#### [`ComplexComponent`](components/ComplexComponent.hpp) - Abstract Intermediate Class
- **Inheritance**: `BaseComponent`
- **ComponentClass**: `Complex`
- **Purpose**: Base for components requiring equivalent circuit models (capacitors, CPE)
- **Key Members**:
  - `resistor_eq` - Equivalent resistor model
  - `current_cs` - Equivalent current source model
- **Virtual Methods**:
  - `Integrate()` - Perform numerical integration
  - `SetupComponent()` - Initialize component state
  - `CheckComponent()` - Validate component state

---

#### [`Capacitor<INTEGRATOR>`](components/Capacitor.hpp) - Templated Component
- **Inheritance**: `ComplexComponent`
- **Template Parameter**: `INTEGRATOR` - Numerical integration method (EULER, FOURPOINTS, DIETHELM)
- **Purpose**: Models a capacitor with various integration methods
- **Key Members**:
  - `c` - Capacitance value
  - `v0` - Initial voltage
  - `integrator` - Integration method instance

---

#### [`CPE<INTEGRATOR>`](components/CPE.hpp) - Constant Phase Element
- **Inheritance**: `ComplexComponent`
- **Template Parameter**: `INTEGRATOR` - Numerical integration method
- **Purpose**: Models Constant Phase Element (fractional order capacitor)
- **Key Members**:
  - `c` - Capacitance
  - `alpha` - Fractional order parameter
  - `gamma` - Gamma function value
  - `integrator` - Fractional integrator instance

---

#### [`VoltageSource`](components/VoltageSource.hpp)
- **Inheritance**: `BaseComponent`
- **ComponentClass**: `Basic`
- **Purpose**: Models an independent voltage source

---

#### [`CurrentSource`](components/CurrentSource.hpp)
- **Inheritance**: `BaseComponent`
- **ComponentClass**: `Basic`
- **Purpose**: Models an independent current source

---

### 3. Integration Methods (Templates)

#### [`Weights<EULER>`](components/Integrators.hpp)
- **Type**: Template Specialization
- **Purpose**: Forward/Backward Euler integration
- **Members**:
  - `Nw = 2` - Number of weights
  - `CorrectorWeighs[]` = {0.5, 0.5}
  - `PredictorWeighs[]` = {0.0, 1.0}

---

#### [`Weights<FOURPOINTS>`](components/Integrators.hpp)
- **Type**: Template Specialization
- **Purpose**: 4-point predictor-corrector method
- **Members**:
  - `Nw = 4` - Number of weights

---

#### [`Weights<DIETHELM>`](components/Integrators.hpp)
- **Type**: Template Specialization
- **Purpose**: Diethelm's method for fractional calculus

---

### 4. Utility Classes

#### [`DParams`](components/Utility.hpp)
- **Purpose**: Parameter container for component configuration
- **Implementation**: Wrapper around `std::map<std::string, std::string>`
- **Template Method**: `get<T>(string)` - Type-safe parameter retrieval

---

#### [`DMap<T>`](components/Utility.hpp)
- **Purpose**: Bidirectional map for node name to index mapping
- **Implementation**: Wrapper around two `std::map` instances

---

#### [`DMat<T>`](components/Utility.hpp)
- **Purpose**: Matrix container template
- **Implementation**: Wrapper around `std::vector<std::vector<T>>`

---

### 5. Component Factory

#### [`Components::MakeError`](components/Components.hpp)
- **Purpose**: Exception class for component creation errors

#### [`Components::Make()`](components/Components.hpp)
- **Purpose**: Factory function to create components from parameters

#### [`Components::Cast<T>()`](components/Components.hpp)
- **Purpose**: Type-safe casting between component types

---

## Design Patterns Used

### 1. **Template Method Pattern**
- `Capacitor<INTEGRATOR>` and `CPE<INTEGRATOR>` use template parameters to specify integration behavior

### 2. **Factory Pattern**
- `Components::Make()` creates appropriate component instances based on parameters

### 3. **Composite Pattern**
- `ComplexComponent` composes `Resistor` and `CurrentSource` to model complex behavior

### 4. **Strategy Pattern**
- Integration methods (`EULER`, `FOURPOINTS`, `DIETHELM`) are interchangeable strategies

---

## Component Type Enum

```cpp
enum class ComponentType {
    Resistor,
    Capacitor,
    Inductor,
    CPE,
    VoltageSource,
    CurrentSource
};
```

---

## Component Class Enum

```cpp
enum class ComponentClass{
   Basic,    // Simple components (Resistor, sources)
   Complex   // Components requiring equivalent circuits (Capacitor, CPE)
};
```

---

## File Structure Summary

| File | Class/Structure | Purpose |
|------|------------------|---------|
| `Circuit.hpp` | `BaseCircuit` | Main solver |
| `BaseComponent.hpp` | `BaseComponent` | Abstract base |
| `Resistor.hpp` | `Resistor` | Basic component |
| `VoltageSource.hpp` | `VoltageSource` | Basic component |
| `CurrentSource.hpp` | `CurrentSource` | Basic component |
| `ComplexComponent.hpp` | `ComplexComponent` | Composite base |
| `Capacitor.hpp` | `Capacitor<T>` | Templated component |
| `CPE.hpp` | `CPE<T>` | Fractional component |
| `Integrators.hpp` | `Weights<T>` | Integration methods |
| `Utility.hpp` | DParams, DMap, DMat | Infrastructure |
| `Components.hpp` | Make, Cast | Factory |

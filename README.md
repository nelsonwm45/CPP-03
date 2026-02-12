# CPP Module 03

## 📝 Overview

This module focuses on **Inheritance** in C++. It explores how to create derived classes, manage resources, and handle complex inheritance scenarios like the **Diamond Problem** using virtual inheritance.

## 📂 Project Structure

### ex00: Aaaaand... OPEN!
Introduction to basic inheritance.
*   **`ClapTrap` Class**: The base class.
    *   **Attributes**: Name, Hit Points (10), Energy Points (10), Attack Damage (0).
    *   **Public Methods**: `attack()`, `takeDamage()`, `beRepaired()`.
    *   Destructor and Constructors print messages to trace creation/destruction order.

### ex01: Serena, my love!
Creating a derived class.
*   **`ScavTrap` Class**: Inherits from `ClapTrap`.
    *   **Attributes**: Different initial values (Hit Points: 100, Energy Points: 50, Attack Damage: 20).
    *   **New Feature**: `guardGate()` puts the ScavTrap in Gate keeper mode.
    *   **`attack()`**: Overrides `ClapTrap::attack()` to print a different message.
    *   Destructor/Constructor chaining is demonstrated.

### ex02: Repetitive work
Creating another derived class.
*   **`FragTrap` Class**: Inherits from `ClapTrap`.
    *   **Attributes**: Different initial values (Hit Points: 100, Energy Points: 100, Attack Damage: 30).
    *   **New Feature**: `highFivesGuys()` requests a positive high five.
    *   Destructor/Constructor chaining is demonstrated.

### ex03: Now it’s weird!
Solving the Diamond Problem.
*   **`DiamondTrap` Class**: Inherits from both `ScavTrap` and `FragTrap`.
*   **Virtual Inheritance**: `ScavTrap` and `FragTrap` virtually inherit from `ClapTrap` to ensure only one instance of the base class exists.
*   **Attributes**:
    *   **Hit Points**: From `FragTrap` (100).
    *   **Energy Points**: From `ScavTrap` (50).
    *   **Attack Damage**: From `FragTrap` (30).
    *   **Name**: Has its own private `_name` attribute, shadowing `ClapTrap::name`.
*   **`whoAmI()`**: Prints its own name and the `ClapTrap` name.
*   Uses `ScavTrap::attack()` for attacking.

## 🛠️ Compilation & Usage

Each exercise has its own `Makefile`.

### ex00
```bash
cd ex00
make
./ClapTrap
```

### ex01
```bash
cd ex01
make
./ScavTrap
```

### ex02
```bash
cd ex02
make
./FragTrap
```

### ex03
```bash
cd ex03
make
./DiamondTrap
```

## 🧹 Housekeeping
To clean up object files and executables in any directory:
```bash
make clean
make fclean
```

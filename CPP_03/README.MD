# 📦 CPP Module 03 — Inheritance

## 🧠 Overview

This module introduces **inheritance in C++**, allowing classes to reuse and extend functionality from other classes.

Main topics:
- inheritance
- constructor and destructor chaining
- method overriding
- multiple inheritance

We build a hierarchy of classes based on a base class: `ClapTrap`.

---

## 🤖 ex00 — ClapTrap

Implemented a base class representing a simple robot.

### 💡 What I learned
- how to design a basic class with attributes and behavior
- managing object state (hit points, energy points, attack damage)
- enforcing conditions (cannot act when no energy or health)
- importance of constructors and destructors

### 🔑 Key idea

The class controls its own state and behavior:
- attack → costs energy and deals damage  
- takeDamage → reduces hit points  
- beRepaired → restores hit points  

---

## 🛡️ ex01 — ScavTrap

Created a derived class from `ClapTrap`.

### 💡 What I learned
- how to inherit from a base class
- how constructors and destructors are chained:
  - base class is constructed first
  - derived class is destroyed first
- how to override member functions (like `attack()`)

### 🔑 Key idea

`ScavTrap` reuses `ClapTrap` but changes behavior and adds:
- different stats
- a special ability: `guardGate()`

---

## 💥 ex02 — FragTrap

Added another derived class with different behavior.

### 💡 What I learned
- reusing base functionality across multiple derived classes
- customizing attributes and behavior per class
- maintaining consistent class structure

### 🔑 Key idea

`FragTrap` extends `ClapTrap` with:
- higher stats
- a unique function: `highFivesGuys()`

---

## 💎 ex03 — DiamondTrap

Implemented a class with **multiple inheritance**:
- inherits from both `ScavTrap` and `FragTrap`

### 💡 What I learned
- how multiple inheritance works in C++
- handling ambiguity between base classes
- understanding the "diamond problem"
- controlling which parent’s behavior is used

### 🔑 Key idea

`DiamondTrap` combines:
- attack → from `ScavTrap`
- stats → from both `ScavTrap` and `FragTrap`
- its own identity with an additional name

Also implements:
- `whoAmI()` → shows both its own name and its ClapTrap name

---

## 🔑 Key Concepts

### 🔹 Inheritance

Allows a class to reuse and extend another class:

- base class → `ClapTrap`
- derived classes → `ScavTrap`, `FragTrap`, `DiamondTrap`

---

### 🔹 Constructor & Destructor Chaining

- base class constructor is called first  
- derived class constructor runs after  
- destruction happens in reverse order  

---

### 🔹 Method Overriding

Derived classes can redefine behavior:

- same function name  
- different implementation  

---

### 🔹 Multiple Inheritance

A class can inherit from multiple parents:

- may cause ambiguity  
- must explicitly choose which parent’s method to use  

---

### 🔹 The Diamond Problem

Occurs when:
- two classes inherit from the same base class  
- a third class inherits from both  

This can lead to duplicate base class instances if not handled properly.

---

## 🚀 Key Takeaways

- Inheritance allows code reuse and extension
- Constructor/destructor order is important
- Derived classes can override behavior
- Multiple inheritance increases complexity and must be handled carefully
- Understanding class relationships is key to clean design

---

## ✨ Summary

This module builds understanding of:
- class hierarchies
- inheritance structure
- object lifecycle in inheritance
- combining behaviors across multiple classes

It introduces more advanced object-oriented design patterns in C++.
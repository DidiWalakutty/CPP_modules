# 📦 CPP Module 02 — Fixed-Point & Operator Overloading

## 🧠 Overview

This module introduces:
- ad-hoc polymorphism (function/operator overloading)
- operator overloading
- the Orthodox Canonical Form (Rule of 4)

We implement a custom **fixed-point number class** and extend it step by step.

---

## 🧮 ex00 — Orthodox Canonical Form

Implemented a class following the **Orthodox Canonical Form**.

### 💡 What I learned
- structure of a well-formed C++ class
- importance of controlling object lifecycle
- difference between:
  - default constructor
  - copy constructor
  - copy assignment operator
  - destructor

### 🔑 Key idea

Every class must correctly handle:
- creation  
- copying  
- assignment  
- destruction  

---

## 🔢 ex01 — Fixed-Point Numbers

Extended the class to represent **fixed-point numbers**.

### 💡 What I learned
- difference between:
  - integers
  - floating-point numbers
  - fixed-point representation
- how to convert between types:
  - `int → fixed`
  - `float → fixed`
  - `fixed → int`
  - `fixed → float`
- using `roundf` for precision

### 🔑 Key idea

A fixed-point number stores:
- an integer value  
- a fixed number of fractional bits  

---

## 🖨️ Operator Overloading (<<)

Implemented:

```cpp
std::ostream& operator<<(std::ostream& os, const Fixed& value);
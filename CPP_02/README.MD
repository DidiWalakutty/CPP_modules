# 📦 CPP Module 02 — Fixed-Point & Operator Overloading

## 🧠 Overview

This module introduces:
- ad-hoc polymorphism (function/operator overloading)
- operator overloading
- the Orthodox Canonical Form (Rule of 4)

We implement a custom fixed-point number class and extend it step by step.

---

## 🧮 ex00 — Orthodox Canonical Form

Implemented a class following the Orthodox Canonical Form.

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

Extended the class to represent fixed-point numbers.

### 💡 What I learned
- difference between:
  - integers
  - floating-point numbers
  - fixed-point representation
- how to convert between types:
  - int → fixed
  - float → fixed
  - fixed → int
  - fixed → float
- using roundf for precision

### 🔑 Key idea

A fixed-point number stores:
- an integer value  
- a fixed number of fractional bits  

---

## 🖨️ Operator Overloading (<<)

Implemented an overload of the insertion operator to print Fixed values.

### 💡 What I learned
- how to overload operators
- how to integrate custom types with std::cout
- difference between member and non-member functions

---

## ⚙️ ex02 — Operator Overloading

Added full operator support to the class.

### 💡 What I learned

Comparison operators:
- >, <, >=, <=, ==, !=

Arithmetic operators:
- +, -, *, /

Increment / Decrement:
- pre-increment (++a)
- post-increment (a++)
- pre-decrement (--a)
- post-decrement (a--)

Static functions:
- min / max (const and non-const versions)

---

## 🔑 Key Concepts

### 🔹 Orthodox Canonical Form

Every class must implement:
- default constructor  
- copy constructor  
- copy assignment operator  
- destructor  

Ensures proper control over object lifecycle and copying behavior.

---

### 🔹 Fixed-Point Representation

Instead of storing floats directly:
- store value as an integer  
- use a fixed number of fractional bits  

Example:
- 8 fractional bits → precision = 1 / 256  

---

### 🔹 Operator Overloading

Allows custom types to behave like built-in types.

Example:
Fixed a(5);
Fixed b(2);
Fixed c = a + b;

This makes code more readable and intuitive.

---

### 🔹 Pre vs Post Increment

- ++a → increment first, then return  
- a++ → return old value, then increment  

---

### 🔹 Static Member Functions

Functions that belong to the class, not instances.

Example:
Fixed::max(a, b);

---

## 🚀 Key Takeaways

- The Orthodox Canonical Form ensures safe and predictable object behavior
- Operator overloading enables natural syntax for custom types
- Fixed-point numbers provide a balance between precision and performance
- Understanding copy vs assignment is essential in C++
- Pre/post increment behave differently and must be implemented carefully

---

## ✨ Summary

This module deepens understanding of:
- class design and lifecycle
- operator overloading
- numeric representations
- writing intuitive and reusable code

It forms the foundation for building more advanced C++ abstractions.
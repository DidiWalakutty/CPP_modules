# 📦 CPP Module 04 — Polymorphism

## 🧠 Overview

This module introduces **subtype polymorphism in C++**, allowing objects to behave differently depending on their actual type, even when accessed through a base class pointer.

Main topics:
- polymorphism  
- virtual functions  
- abstract classes  
- deep copying  
- dynamic memory management  

We build a hierarchy of classes based on a base class: `Animal`.

---

## 🐾 ex00 — Polymorphism

Implemented a base class `Animal` and derived classes `Dog` and `Cat`.

### 💡 What I learned
- how polymorphism works using base class pointers  
- how to use the `virtual` keyword  
- how function overriding enables different behavior  
- the difference between correct and incorrect polymorphism  

### 🔑 Key idea

Even when using a base class pointer, the correct function is called based on the actual object type:

- `Animal* → Dog` calls Dog’s `makeSound()`  
- `Animal* → Cat` calls Cat’s `makeSound()`  

Also implemented:
- `WrongAnimal` and `WrongCat` to show what happens without `virtual`

---

## 🧠 ex01 — Brain

Extended `Dog` and `Cat` with a dynamically allocated `Brain`.

### 💡 What I learned
- how to work with dynamic memory (`new` / `delete`)  
- how to implement the Rule of Three  
- the difference between deep copy and shallow copy  
- why copying pointers directly is dangerous  

### 🔑 Key idea

Each object must own its own memory:

- `Brain` is allocated per object  
- copies must duplicate the data, not the pointer  

Also practiced:
- deleting objects through base class pointers  
- ensuring correct destructor order  

---

## 🚫 ex02 — Abstract Class

Made `Animal` non-instantiable by turning it into an abstract class.

### 💡 What I learned
- how to use pure virtual functions  
- how abstract classes enforce design constraints  
- how to define interfaces in C++  

### 🔑 Key idea

Some classes are only meant to be used as a base, not instantiated directly:

- `Animal` becomes a blueprint  
- only derived classes like `Dog` and `Cat` can be created  

---

## 🔑 Key Concepts

### 🔹 Polymorphism

Allows different objects to respond differently to the same function call:

- achieved using base class pointers and virtual functions  

---

### 🔹 Virtual Functions

Enable runtime behavior selection:

- function is resolved based on actual object type  
- required for proper polymorphism  

---

### 🔹 Abstract Classes

Classes that cannot be instantiated:

- contain at least one pure virtual function  
- define a common interface for derived classes  

---

### 🔹 Deep Copy

Ensures objects do not share the same memory:

- required when using dynamic allocation  
- prevents unexpected side effects and memory issues  

---

### 🔹 Rule of Three

If a class manages memory, it must implement:

- copy constructor  
- copy assignment operator  
- destructor  

---

## 🚀 Key Takeaways

- Polymorphism allows flexible and extensible design  
- Virtual functions are essential for correct behavior  
- Abstract classes help enforce structure  
- Deep copy prevents memory bugs  
- Managing memory correctly is critical in C++  

---

## ✨ Summary

This module builds understanding of:
- runtime behavior (polymorphism)  
- safe memory management  
- abstract design patterns  

It’s a great step in writing scalable and maintainable C++ code.
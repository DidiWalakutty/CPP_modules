# 📦 CPP Module 05 — Exceptions

## 🧠 Overview

This module introduces **exceptions in C++**, focusing on error handling, class design with constraints, and controlled execution flow.

Main topics:
- exceptions  
- try/catch handling  
- class invariants  
- interaction between classes  
- abstract classes  

We build a system around bureaucrats and forms.

---

## 🧑‍💼 ex00 — Bureaucrat

Implemented a `Bureaucrat` class with strict grade constraints.

### 💡 What I learned
- how to throw and catch exceptions  
- enforcing constraints in constructors and methods  
- working with constant attributes  
- operator overloading (`<<`)  

### 🔑 Key idea

A `Bureaucrat` always has a valid grade:

- grade range: 1 (highest) → 150 (lowest)  
- invalid grade → exception thrown  

Also implemented:
- `incrementGrade()` and `decrementGrade()` with bounds checking  

---

## 📄 ex01 — Form

Introduced a `Form` class that bureaucrats can sign.

### 💡 What I learned
- interaction between multiple classes  
- enforcing permissions based on grade  
- designing safe APIs with validation  
- handling errors across class boundaries  

### 🔑 Key idea

A form can only be signed if the bureaucrat has a high enough grade:

- form has required grades for signing and execution  
- signing fails → exception thrown  

Also implemented:
- `beSigned()` in `Form`  
- `signForm()` in `Bureaucrat` with clear success/failure messages  

---

## 🏛️ ex02 — AForm & Concrete Forms

Refactored `Form` into an abstract class `AForm` and created concrete implementations.

### 💡 What I learned
- how to design abstract base classes  
- separating shared logic from specific behavior  
- implementing polymorphic execution  
- organizing code for scalability  

### 🔑 Key idea

Forms define *what* must happen, derived classes define *how* it happens:

Implemented:
- `ShrubberyCreationForm` → creates a file with ASCII trees  
- `RobotomyRequestForm` → random success/failure (50%)  
- `PresidentialPardonForm` → prints a pardon message  

Also added:
- `execute()` with validation:
  - form must be signed  
  - bureaucrat must have sufficient grade  

---

## 🧑‍🔧 ex03 — Intern

Implemented an `Intern` class that creates forms dynamically.

### 💡 What I learned
- dynamic object creation based on input  
- avoiding messy conditional logic  
- using mapping/lookup patterns instead of long if/else chains  

### 🔑 Key idea

The intern acts as a factory:

- takes form name + target  
- returns the correct form instance  

If the form does not exist:
- prints an error message  

---

## 🔑 Key Concepts

### 🔹 Exceptions

Used to handle errors safely:

- `throw` → raise an error  
- `try/catch` → handle it  

---

### 🔹 Class Invariants

Objects must always remain valid:

- `Bureaucrat` grade must stay within bounds  
- `Form` must enforce signing/execution rules  

---

### 🔹 Operator Overloading

Custom output using:

- `operator<<` for clean printing  

---

### 🔹 Abstract Classes

Used to define common structure:

- `AForm` cannot be instantiated  
- derived classes implement behavior  

---

### 🔹 Polymorphism

Allows executing different form behaviors through a common interface.

---

## 🚀 Key Takeaways

- Exceptions provide safe error handling  
- Classes must enforce their own validity  
- Abstract classes improve design structure  
- Polymorphism enables flexible behavior  
- Clean code avoids large conditional blocks  

---

## ✨ Summary

This module builds understanding of:
- error handling with exceptions  
- structured class interaction  
- abstract design and polymorphism  

It introduces more robust and scalable patterns used in real-world C++ applications.
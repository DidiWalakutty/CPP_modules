# 📦 CPP Module 01 — Memory & References

## 🧠 Overview

This module focuses on **memory management and references in C++**.

Main topics:
- stack vs heap allocation
- pointers and references
- dynamic memory (`new` / `delete`)
- pointers to member functions
- file manipulation
- `switch` statements

---

## 🧟 ex00 — BraiiiiiiinnnzzzZ

Implemented a `Zombie` class and explored stack vs heap allocation.

### 💡 What I learned
- difference between stack and heap allocation
- when to use `new` vs automatic variables
- importance of destructors for cleanup
- returning objects from functions safely

### 🔑 Key idea

Heap vs stack allocation:

- `newZombie()` → allocates on the heap → must be deleted manually  
- `randomChump()` → allocates on the stack → automatically destroyed  

---

## 🧟‍♂️ ex01 — Moar brainz!

Implemented a function that creates a **dynamic array of objects**.

### 💡 What I learned
- how to allocate multiple objects using `new[]`
- how to initialize each object in an array
- importance of `delete[]` for proper cleanup

### 🔑 Key idea

- `new[]` allocates multiple objects  
- must always be paired with `delete[]`  

---

## 🧠 ex02 — HI THIS IS BRAIN

Explored the difference between pointers and references.

### 💡 What I learned
- pointers store memory addresses
- references act as aliases to existing variables
- both give access to the same data in different ways

### 🔑 Key idea

- pointer → can be reassigned and can be null  
- reference → always refers to the same object and cannot be null  

---

## ⚔️ ex03 — Unnecessary violence

Implemented classes using references and pointers.

### 💡 What I learned
- difference between:
  - reference members (`HumanA`)
  - pointer members (`HumanB`)
- when a reference must always be initialized
- when a pointer allows optional ownership

### 🔑 Key idea

- `HumanA` always has a weapon → uses reference  
- `HumanB` may not have a weapon → uses pointer  

---

## 📄 ex04 — Sed is for losers

Implemented file reading and string replacement.

### 💡 What I learned
- reading from files using C++ streams
- writing to new files
- manipulating strings without using `std::string::replace`
- handling file errors safely

---

## 📢 ex05 — Harl 2.0

Used **pointers to member functions** to avoid large `if/else` chains.

### 💡 What I learned
- how to store and call member functions dynamically
- cleaner alternatives to repetitive conditional logic

### 🔑 Key idea

- map input strings to member function pointers  
- call functions based on input without multiple `if/else`  

---

## 🔄 ex06 — Harl filter

Implemented filtering using a `switch` statement.

### 💡 What I learned
- how `switch` works compared to `if/else`
- controlling program flow based on input levels

---

## 🔑 Key Concepts

### 🔹 Stack vs Heap

- Stack → automatic lifetime (destroyed when out of scope)  
- Heap → manual lifetime (must use `delete`)  

---

### 🔹 Pointers vs References

- Pointer:
  - stores an address
  - can be null
  - can be reassigned  

- Reference:
  - alias to an existing variable
  - cannot be null
  - cannot be reassigned  

---

### 🔹 Dynamic Memory

- `new` → allocate single object  
- `new[]` → allocate array  
- `delete` → free single object  
- `delete[]` → free array  

---

### 🔹 Object Lifetime

- stack objects → destroyed automatically  
- heap objects → must be manually deleted  

---

## 🚀 Key Takeaways

- Memory must be managed carefully in C++
- Stack vs heap affects lifetime and responsibility
- References are safer than pointers in many cases
- `new[]` and `delete[]` must always match
- Function pointers can simplify control flow
- Understanding ownership is essential for correct design

---

## ✨ Summary

This module builds a deeper understanding of:
- memory allocation
- object lifetime
- references vs pointers
- clean and structured control flow

These concepts are fundamental for writing safe and efficient C++ code.
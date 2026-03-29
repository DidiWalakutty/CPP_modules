# 📦 CPP Module 00 — Basics of C++

## 🧠 Overview

This module introduces the foundations of C++:
- namespaces
- classes
- member functions
- standard input/output streams
- initialization lists
- `static`
- `const`

Implemented:
- a simple command-line program (`ex00`)
- a small class-based phonebook application (`ex01`)

---

## 📣 ex00 — Megaphone

Implemented a program that prints all input arguments in uppercase.

### 💡 What I learned
- how to use `argc` and `argv`
- how to loop through command-line arguments
- how to use `std::cout` for output
- how to use standard library functions like `std::toupper`
- difference between C++ I/O and C-style printing

### 🔑 Key idea
The program reads each argument, converts every character to uppercase, and prints the result.  
If no arguments are given, it prints a default message.

---

## 📇 ex01 — My Awesome PhoneBook

Implemented an interactive phonebook using two classes:
- `PhoneBook`
- `Contact`

The program supports:
- `ADD`
- `SEARCH`
- `EXIT`

---

## 🏗️ Main Concepts Learned

### 🔹 Classes & Objects
- `PhoneBook` manages an array of contacts  
- `Contact` stores individual contact data  

This introduced:
- object creation from class blueprints  
- separating responsibilities between classes  

---

### 🔹 Encapsulation
- contact data is kept private  
- interaction happens through public member functions  

> Keeps internal state protected and code organized

---

### 🔹 Member Functions
Used to:
- set and validate contact data  
- display formatted contact lists  
- display full contact details  
- manage adding and searching contacts  

---

### 🔹 Fixed-Size Storage
- Used a fixed array of 8 contacts  
- No dynamic allocation allowed  

### 💡 What I learned
- how to manage a limited-size container  
- how to overwrite the oldest data when full  

---

### 🔹 Input Handling
Used `std::getline` to safely read user input.

### 💡 What I learned
- handling user input in a loop  
- validating input before storing  
- handling end-of-input (`Ctrl+D`) safely  

---

### 🔹 Output Formatting
Used `std::setw` for structured display.

### 💡 What I learned
- aligning output in columns  
- truncating long text with a dot (`.`)  
- building readable table-like output  

---

## 🔒 const & Initialization

### 💡 What I learned
- using `const` to prevent unintended modifications  
- using initialization lists for constructor setup  

---

## 📝 Additional Improvements

- Added validation for all input fields (not just empty checks)
- Implemented rules for names, phone numbers, and secrets
- Handled EOF (`Ctrl+D`) to exit safely without crashes
- Used modulo logic to overwrite the oldest contact efficiently
- Structured code using helper functions for clarity and reuse

---

## 🚀 Key Takeaways

- Classes combine data and behavior
- Encapsulation improves structure and safety
- Input validation is important for robustness
- Formatting improves usability
- Managing fixed-size data requires careful logic
- Clean code structure improves readability and maintainability

---

## ✨ Summary

This module builds the foundation of C++ by introducing:
- object-oriented programming
- class design
- input/output handling
- data validation
- structured and readable code
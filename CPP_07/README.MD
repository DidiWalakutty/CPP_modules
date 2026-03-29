# 📦 CPP Module 07 — Templates

## 🧠 Overview

This module introduces **templates in C++**, allowing us to write generic, reusable code that works with multiple data types.

Implemented:
- Function templates (`ex00`)
- Generic iteration (`ex01`)
- A templated dynamic array class (`ex02`)

---

## 🔁 ex00 — Function Templates

Implemented generic functions:
- `swap`
- `min`
- `max`

### 💡 What I learned
- Templates allow one function to work with different types
- Avoid code duplication
- Type safety compared to `void*` or macros
- Functions require compatible operators (e.g. `<`, `>`)

---

## 🔄 ex01 — iter

Implemented a function that applies another function to each element of an array.

### 💡 What I learned
- How to pass functions as parameters
- Templates with multiple types (`T`, function type)
- Difference between:
  - `T&` → modifiable
  - `const T&` → read-only
- Const-correctness enforced by the compiler

---

## 📦 ex02 — Array

Implemented a templated dynamic array class.

### 🏗️ Features
- Dynamic memory management using `new[]` / `delete[]`
- Deep copy (Rule of Three)
- Safe access with `operator[]`
- Size tracking with `size()`

---

## 🔑 Key Concepts

### 🔹 Templates
Allow writing generic code:
```cpp
Array<int>
Array<std::string>

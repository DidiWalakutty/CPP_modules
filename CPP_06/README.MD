# 📦 CPP Module 06 — Casts

## 🧠 Overview

This module introduces **type casting in C++**, focusing on converting between types safely and understanding how data is represented.

Main topics:
- scalar conversions  
- static casting  
- reinterpret casting  
- type identification  
- low-level type manipulation  

We explore how values and pointers can be transformed between different types.

---

## 🔢 ex00 — Scalar Converter

Implemented a `ScalarConverter` class to convert a string literal into multiple scalar types.

### 💡 What I learned
- how to detect and parse different literal types  
- converting between `char`, `int`, `float`, and `double`  
- handling edge cases like overflow and invalid input  
- working with special floating-point values (`nan`, `inf`)  

### 🔑 Key idea

A single input can represent multiple types:

- detect the original type  
- convert it to the other scalar types  
- handle impossible or non-displayable conversions  

Also handled:
- pseudo-literals like `nan`, `+inf`, `-inff`  
- display formatting for each type  

---

## 🔁 ex01 — Serialization

Implemented a `Serializer` class to convert pointers to integers and back.

### 💡 What I learned
- how pointers can be represented as integers  
- using `reinterpret_cast` for low-level conversions  
- understanding memory addresses as raw data  

### 🔑 Key idea

A pointer can be safely converted to an integer and back without losing information:

- `serialize(Data*) → uintptr_t`  
- `deserialize(uintptr_t) → Data*`  

Ensured:
- the deserialized pointer matches the original  

---

## 🧩 ex02 — Identify Real Type

Implemented runtime type identification without using `typeinfo`.

### 💡 What I learned
- how to use `dynamic_cast`  
- identifying types through pointers and references  
- handling casting failures  

### 🔑 Key idea

Polymorphism allows identifying the real type at runtime:

- `Base*` can point to `A`, `B`, or `C`  
- `dynamic_cast` reveals the actual type  

Implemented:
- `generate()` → randomly creates A, B, or C  
- `identify(Base*)` → identifies using pointer  
- `identify(Base&)` → identifies using reference  

---

## 🔑 Key Concepts

### 🔹 Static Cast

Used for safe and explicit type conversions:

- compile-time checked  
- commonly used for scalar conversions  

---

### 🔹 Reinterpret Cast

Used for low-level conversions:

- converts pointers to integers and back  
- no safety checks  

---

### 🔹 Dynamic Cast

Used for runtime type identification:

- works with polymorphic types  
- returns `nullptr` or throws if invalid  

---

### 🔹 Scalar Conversion

Converting between basic data types:

- `char`, `int`, `float`, `double`  
- may fail or overflow  

---

## 🚀 Key Takeaways

- Different casts serve different purposes  
- Always choose the safest cast available  
- Runtime type identification relies on polymorphism  
- Low-level casting should be used carefully  
- Not all conversions are valid or meaningful  

---

## ✨ Summary

This module builds understanding of:
- type conversion between scalar values  
- pointer manipulation and serialization  
- runtime type identification  

It introduces both high-level and low-level casting techniques in C++.
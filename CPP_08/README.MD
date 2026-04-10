# 📦 CPP Module 08 — Templated Containers, Iterators & Algorithms

## 🧠 Overview

This module introduces working with **STL containers, iterators, and algorithms** in C++.

Implemented:
- Searching in containers using algorithms (`ex00`)
- A bounded container with span calculations (`ex01`)
- Making a non-iterable container iterable (`ex02`)

---

## 🔍 ex00 — easyfind

Implemented a function template that searches for a value inside a container.

### 💡 What I learned
- How to use STL algorithms like `std::find`
- Working with iterators (`begin()` / `end()`)
- Templates with containers as parameters
- How standard containers handle search (return iterator or throw)
- Difference between sequence containers and associative containers

---

## 📏 ex01 — Span

Implemented a class that stores a fixed number of integers and calculates distances between them.

### 🏗️ Features
- Fixed capacity container using `std::vector`
- Adding single and multiple numbers (iterator range)
- Exception handling for overflow and insufficient data
- Efficient calculation of:
  - Shortest span (smallest difference between numbers)
  - Longest span (difference between min and max)

### 💡 What I learned
- Using STL algorithms (`std::sort`, `std::min_element`, `std::max_element`)
- Working with ranges using iterators
- Importance of checking bounds and edge cases
- Time complexity differences (sorting vs brute force)

---

## 🧬 ex02 — MutantStack

Implemented a stack that is also iterable.

### 🏗️ Features
- Inherits from `std::stack`
- Keeps all standard stack operations (`push`, `pop`, `top`, `size`)
- Adds iterator support (`begin()`, `end()`)
- Supports const and non-const iteration

### 💡 What I learned
- What a container adapter is (`std::stack`)
- That `std::stack` uses an underlying container (default: `std::deque`)
- Accessing protected members through inheritance (`c`)
- Exposing iterators from the underlying container
- Difference between `iterator` and `const_iterator`
- How to make a non-iterable structure iterable

---

## 🔑 Key Concepts

### 🔹 Iterators
Allow traversal over containers:
# Personal Health Record Blockchain System

## Overview
This project demonstrates a **Health Record Blockchain** implemented in C++. It is a prototype designed to handle patient and doctor interactions while securely storing medical records using blockchain principles. 

The project emphasizes modern C++ features and OOP principles, and it can be extended for GUI-based applications, such as a Qt framework GUI, replacing high-level languages like Python or C#.


Why C++?
While high-level languages like Python and C# are popular for such projects, C++ offers:

Higher performance and fine-grained control.
Robust memory management using modern C++ standards.
Direct compatibility with GUI frameworks like Qt for native applications.

---

## Features
**Blockchain:** Secure and immutable storage of medical records.
**Object-Oriented Design:** Classes for Doctors, Patients implement encapsulation, inheritance, and polymorphism.
**Modern C++ Features:**
  - Smart pointers (`std::shared_ptr`) for efficient memory management.
  - STL Containers (`std::vector`) for dynamic storage.
**Design Patterns:**
  - Observer Pattern
  - Prototype Pattern (through std::enable_shared_from_this)
  - Composition Pattern
---

## Dependencies
- C++14 or later
- CMake (build system)
- Compiler supporting modern C++ (e.g., GCC, Clang, MSVC)

---

## Usage
1. Clone the repository:
   ```bash
   git clone https://github.com/AbyssWatcher-17/Health-Record-Blockchain.git
   cd Personal-Health-Record-Blockchain

2.Build the project using CMake (in Linux):   
    mkdir build
    cd build
    cmake ..
    make

3.Run the executable:
./Health-Record-Blockchain


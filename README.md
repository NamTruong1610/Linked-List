# MyList Library and Custom MyInteger

This repository provides an implementation of a doubly linked list, `MyList`, as a C++ template class, along with a custom integer type `MyInteger`. The project demonstrates basic list operations such as inserting and removing elements at both ends, as well as deep copying through copy constructors and assignment operators. It also includes a comprehensive set of tests using the [Google Test framework](https://github.com/google/googletest).

## Project Structure

- **myList.hpp**  
  Declares the `MyList` template class that implements a doubly linked list:
  - **Node Structure:**  
    Each node holds data of type `T` and pointers to the previous and next nodes.
  - **Constructors & Destructor:**  
    Includes a default constructor, an initializer list constructor, a copy constructor, and a destructor that frees allocated memory.
  - **Member Functions:**  
    Provides operations for:
    - Accessing the first and last elements (`front()`, `back()`).
    - Inserting elements at the front and back (`push_front()`, `push_back()`).
    - Removing elements from the front and back (`pop_front()`, `pop_back()`).
    - Checking if the list is empty and obtaining its size.

- **myInteger.hpp**  
  Defines the `MyInteger` class, which wraps an integer value and supports:
  - Default and parameterized construction.
  - Copy construction and assignment.
  - A pre-increment operator.
  - Comparison and equality operators.
  - A stream insertion operator for easy printing.

- **myList.cpp**  
  Implements the member functions declared in `myList.hpp`, including:
  - Memory management (constructors, destructor).
  - List operations such as insertion and removal.
  - Ensuring that deep copies are made in copy construction and assignment.

- **main.cpp**  
  Contains a suite of tests using the Google Test framework to verify:
  - The functionality of `MyList` for different types (e.g., `int`, `std::string`, `MyInteger`).
  - Proper operation of the copy constructor and assignment operator (ensuring deep copy).
  - Correct behavior of list operations (push, pop, and access functions) under various scenarios.

## Getting Started

### Prerequisites

- **C++ Compiler:**  
  A C++ compiler with C++17 support (e.g., `g++` or `clang++`).

- **Google Test:**  
  Make sure you have [Google Test](https://github.com/google/googletest) installed and properly configured.

### Compilation

Assuming you have Google Test installed, compile the project from the terminal with a command similar to:

```bash
g++ -std=c++17 -I/path/to/googletest/include -L/path/to/googletest/lib main.cpp myList.cpp -lgtest -lgtest_main -pthread -o runTests

# CPP-[projects from 05 to 09]
This project was developed for 42 school. For comprehensive information regarding the requirements, please consult the PDF file in the subject folder of the repository. Furthermore, I have provided my notes and a concise summary below.

```diff
+ keywords: object oriented programming
+ projects must comply with the C++98 standard (42 school requirement)
+ relation among types. Classes to define types (user-defined types, classes and enumerations)
+ C++ augments the built-in types and operations with a set of abstraction mechanisms (leap of abstraction from C - compact type performance code)
```

## High-level Overview

- C++11 (and derived forms) and Boost libraries are forbidden. The following functions are forbidden too: *printf(), *alloc() and free(). If you use them, your grade will be 0 and that’s it.
- You are allowed to use the STL in the Module 08 and 09 only. That means: no Containers (vector/list/map/and so forth) and no Algorithms (anything that requires to include the <algorithm> header) until then.
- When you allocate memory (by using the new keyword), you must avoid memory leaks.
- From Module 02 to Module 09, your classes must be designed in the Orthodox Canonical Form, except when explicitely stated otherwise.

0. C++ module 05 - repetition and exceptions, try catch

```
try {
  // Block of code to try
  throw exception; // Throw an exception when a problem arise
}
catch () {
  // Block of code to handle errors
}
```

### References
[std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what)<br />
[A Tour of C++ (Second edition)](https://www.stroustrup.com/tour2.html) [Exercises](https://www.stroustrup.com/4thExercises.pdf)<br />
[The Design of C++ , lecture by Bjarne Stroustrup](https://www.youtube.com/watch?v=69edOm889V4)<br />
[Bjarne Stroustrup - The Essence of C++](https://www.youtube.com/watch?v=ZXc_z1sNbfA)<br />

## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------|
| **try catch** | `try throw catch` | When an error occurs, C++ will throw an exception. **try** defines a block of code to be tested for errors, **throw** throws an exception when a problem is detected, **catch** defines a block of code to be executed, if an error occurs in the try block. It will use throw for the tailored message. |
| **ellipsis** | `catch(...)` | If you don't know the **throw** type used in the **try** block, ellipsis notation can be applied for handling any type of exception. |
| **what** | `const char* what() const throw {}` | No parameters, pointer to a null terminated string with explanatory information about the error. Valid until the exception object from which is obtained is destroyed or a non-const member function on the exception object is called. [std::exception](https://en.cppreference.com/w/cpp/error/exception), [std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what), **EXCEPTION IS AN OBJECT**, `what()` returns an explanatory string. |
| **Output string stream** | `std::ostringstream` | Characters can be inserted into the stream. |
| **Abstract class** | `a common interface for a group of related classes` | An abstract class is a class that cannot be instantiated on its own and is intended to be subclassed. It often contains one or more pure virtual functions. Define a common interface for a group of related classes. It provides a base class that other classes can inherit from and implement the abstract methods. **You cannot create an instance of an abstract class directly.** |
| **Pure virtual function** | `virtual void pureVirtualFunction() = 0;` | Assigning 0 to the function declaration. These functions must be overridden by derived classes. |
| **Concrete class** | `can be instantiated` `class ConcreteClass : public AbstractClass` | It provides implementations for all its methods, including any inherited pure virtual functions. Do not contain pure virtual functions. |

```c++
class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function
    void concreteFunction() {
        // Implementation of a concrete function
    }
};

class ConcreteClass : public AbstractClass {
public:
    void pureVirtualFunction() override {
        // Implementation of the pure virtual function
    }
};
```

### References from A Tour of C++ (Stroustrup, 2023)
```c++
class Vector {
public:
  Vector(int s) :elem{new double[s]}, sz{s} {} // construct a vector
  double& operator[](int i) {return elem[i];} // element access: subscripting
  int size() {return sz;}
private:
  double* elem; // pointer to the elements
  int sz; // the number of elements 
}
```

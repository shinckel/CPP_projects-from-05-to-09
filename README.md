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
1. C++ module 06 - Conversion of scalar types, casting

```c++
try {
  // Block of code to try
  throw exception; // Throw an exception when a problem arise
}
catch () {
  // Block of code to handle errors
}
```

### Implicit and explicit type convertions
```c++
int main(void) {
  int a = 5;
  double value = a; // implicit convertion

  double otherValue = 4.2;
  int b = (int)otherValue; // explicit convertion, C style cast

  double newOtherValue = 10.111;
  int c = static_cast<int>(newOtherValue); // explicit convertion, C++ style cast

  Widget* pw = static_cast<Widget*>(pv); // pv is a void* supposed to point to a Widget
  auto dd = reinterpret_cast<Device_driver*>(0xFF00); // 0xFF is supposed to point to a device driver
  char* pc = const_cast<char*>("Casts are inherently dangerous");
}
```

### Class hierarchies
```c++
// Class Hierarchy: set of classes created by derivation, representing concepts that have hierarchical relationships such as "A similey face is a kind of a circle that is a kind of a shape".
// Objects are constructed bottom up (base first) by constructors and destroyed top down (derived first) by destructors.
// For class hierachy navigation, prefer the checked dynamic_cast;
// Use dynamic_cast to a reference type when failure to find the required class is considered a failure or valid alternative;
/*
            shape
            /   \
      circle    triangle
      /
smiley
*/
class Shape {
  public:
    virtual Point center() const =0;
    virtual void move() const =0;
    virtual void draw() const =0;

    virtual ~Shape(){}; // so derived class can delete it through a pointer
}

class Circle : public Shape {
  public:
    Circle(Point p, int rad) : x{p}, r{rad} {}
    Point center() const override {return x};
    // continues...

  private:
    Point x;
    int r;
}

class Smiley : public Circle {
  public:
    Smiley(Point p, int rad) : Circle{p, rad}, mouth{nullptr} {}
    ~Smiley() {
      delete mouth;
      for (auto p : eyes)
        delete p;
    }
    // continues...

  private:
    vector<Shape*> eyes;
    Shape *mouth;
}
```

### Hierarchy navigation — A Tour of C++ page 67 (physical book) or page 47 (online reference)
```c++
// read shape descriptions from input stream "is"
Shape* read_shape(istream &is) {
  // read shape header from "is" and find its kind "k"
  switch (k) {
    case Kind::circle:
      return new Circle{p, r};
    case Kind::smiley:
      Smiley* ps = new Smiley{p, r};
      ps->add_eye(e1);
      ps->add_eye(e2);
      ps->set_mouth(m);
      return ps;
  }
}

// what can we do if we want to use a member function that is only provided by a particular derived class, such as Smiley wink()?
// we can ask: is this Shape a kind of Smiley? USING THE <dynamic_cast> operator
Shape *ps {read_shape(cin)};
if (Smiley *p = dynamic_cast<Smiley*>(ps)) // does ps points to a Smiley?
  // yes it is a Smiley, do something
else
  // not a Smiley, returns nullptr

// it is the same as:
Smiley& r {dynamic_cast<Smiley&>(*ps)} // somewhere, catch std::bad_cast
```

### Abstract and Concrete classes
```c++
// Comments from the book "A Tour of C++", page 56
// Use abstract classes as interfaces when complete separation of interface and implementation is needed;
// An abstract class typically doesn’t need a constructor;
// A class with a virtual function should have a virtual destructor;
// Virtual function table(?);
class AbstractClass {
public:
    virtual void pureVirtualFunction() = 0; // Pure virtual function;
    void concreteFunction() {
        // Implementation of a concrete function;
    }
};

class ConcreteClass : public AbstractClass {
public:
    void pureVirtualFunction() override {
        // Implementation of the pure virtual function;
    }
};
```

### Copy constructor versus assignment operator
```c++
int main(void) {
  Bureaucrat b("Pesto", 5);
  Bureaucrat a = b; // copy constructor, "a" wasn't initialized
  std::cout << a << std::endl; // Bureaucrat: Pesto, Grade: 5
  Bureaucrat c("Jamie", 32);
  a = c; // assignment operator, grade is copied to "a" (name is const)
  std::cout << a << std::endl; // Bureaucrat: Pesto, Grade: 32
}
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

### References
[std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what)<br />
[A Tour of C++ (Second edition)](https://www.stroustrup.com/tour2.html) [Exercises](https://www.stroustrup.com/4thExercises.pdf)<br />
[The Design of C++ , lecture by Bjarne Stroustrup](https://www.youtube.com/watch?v=69edOm889V4)<br />
[Bjarne Stroustrup - The Essence of C++](https://www.youtube.com/watch?v=ZXc_z1sNbfA)<br />
[C Programming Tutorial 21 - Int, Float, and Double Data Types](https://www.youtube.com/watch?v=heULTdxf_yQ)<br />
[Casting in C++](https://www.youtube.com/watch?v=pWZS1MtxI-A)<br />
[A Tour of C++, page 39 — static_cast, page 161 — 14.2.4 Casts](https://elhacker.info/manuales/Lenguajes%20de%20Programacion/C++/A%20Tour%20of%20C++%20-%20Bjarne%20Stroustrup%20(Addison-Wesley,%202014)(193p).pdf)

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
| **std::cerr** | `std::cerr` | |
| **protected** | `class Base { protected: std::string _target; }` | Members declared as protected are accessible within the class itself, by derived classes (subclasses), and by friend classes/functions. However, they are not accessible from outside the class hierarchy. |
| **private** | | Members declared as private are accessible only within the class itself and by friend classes/functions. They are not accessible from derived classes or from outside the class. |
| **#include fstream** | `file.open((_target + "_shrubbery").c_str(), std::ios::out);` | The library provides classes for reading and writing into files or data streams. `fstream` — class that can read and write to files, `ifstream` — class that can read from files, `ofstream` — a class that can write to files. |
| **std::string::compare** | `int compare (const string& str) const;` | `if (str1.compare(str2) != 0) std::cout << str1 << " is not " << str2 << '\n';` |
| **Polymorphism** | `AForm *Intern::makePPF(std::string target) { return new PresidentialPardonForm(target); }` | _Polymorphism:_ Allows you to use a base class pointer to refer to objects of derived classes. _Base Class Pointer:_ `AForm *` is the base class pointer. _Derived Class Object:_ `new PresidentialPardonForm(target)` creates an instance of the derived class. _Dynamic Binding:_ Virtual functions called on the base class pointer will use the derived class's implementation. |
| **static** | `static void converter(std::string literal)` | The convert method is static, meaning it belongs to the class itself rather than any particular instance of the class. This allows you to call the method without creating an instance of ScalarConverter. Static members of a class are not associated with the objects of the class, and when called, they have no this pointer: read more [here](https://en.cppreference.com/w/cpp/language/static). |
| **named casts** | `int value = static_cast<int>(c);` | C++ operator used to perform explicit type conversions. There are four different types: `static_cast` it is not adding new functionalities to C — syntax sugar + compile time checks, `dynamic_cast` performs checks and may return NULL if convertion wasn't successful — runtime checking, `const_cast` for casting away const, `reinterpret_cast` reinterprets memory as something else — read more [here](https://en.cppreference.com/w/cpp/language/reinterpret_cast). **Easily search for casting in your codebase**. |
| **double float** | `42.0 42.0f` | Both have a fractional part, floating point. The difference lays in precision: double has much more — 8 bytes (64 bits) versus 4 bytes (32 bits). Doubles take twice as much memory/space. In C `printf("int: %i, double: %f, float: %f", 1, 1111.1111, 1111.1111F)`, double and float output are different. |
| **uintptr_t** | `uintptr_t ptrs_and_ints[100];` | Portability, it is designed to be able to store any pointer value, making it portable across different platforms and architectures. Converting pointers to integers allows you to serialize (convert to a storable or transmittable format) and deserialize (reconstruct the original format) pointers. Especially useful where you have an array of unstructured memory containing both pointers and integers, now you can be assured that you can safely store a pointer in any of the entries. |

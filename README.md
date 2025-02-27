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
1. C++ module 06 - conversion of scalar types, casting
3. C++ module 07 - templates
4. C++ module 08 — templated containers, iterators, algorithms, extending the functionality of the standard library
5. C++ module 09 — Bitcoin Value Calculation `std::map`, Reverse Polish Notation (RPN) `std::stack`, Merge-Insertion Sort `std::vector`

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
  Bureaucrat a = b; // copy constructor, "a" wasn't initialized;
  std::cout << a << std::endl; // Bureaucrat: Pesto, Grade: 5;
  Bureaucrat c("Jamie", 32);
  a = c; // assignment operator, grade is copied to "a" (name is const);
  std::cout << a << std::endl; // Bureaucrat: Pesto, Grade: 32;
}
```

### References from A Tour of C++ (Stroustrup, 2023)
```c++
class Vector {
public:
  Vector(int s) :elem{new double[s]}, sz{s} {} // construct a vector;
  double& operator[](int i) {return elem[i];} // element access: subscripting;
  int size() {return sz;}
private:
  double* elem; // pointer to the elements;
  int sz; // the number of elements;
}
```

### Vector — A Tour of C++ page 159 (physical book)
```c++
template<typename T>
class Vector {
  allocator<T> alloc; // standard library allocator of space for Ts;
  T* elem; // pointer to first element;
  T* space; // pointer to first unused (and uninitialized) slot;
  T* last; // pointer to last slot;

public:
  int size() const { return space-elem; } // number of elements;
  int capacity() const { return last-elem; } // number of slots available for elements;
  void reserve(int newsz); // increase capacity() to newsz... make room for elements;
  void push_back(const T& t); // copy t into Vector;
  void push_back(T& &t); // move t into Vector;
};

template<typename T>
void Vector<T>::push_back(const T& t) {
  if(capacity() >= size()) { // make sure we have space for t
    reserve(size() == 0 ? 8 : 2 * size()) // double the capacity
  }
  construct_at(space, t); // initialize *space to t ("place t at space")
  ++space;
}
```

### File stream classes — std::ifstream for input file streams and std::ofstream for output file streams
```c++
// istream& getline(istream& is, string& str, char delim);
```

### Sorting
```c
usage: data compression, computer graphics
unsorted A[0:n] —> sorted B[0:n]
find medium -> B[n/2] constant time once you have a sorted array O(1)

Finding a specific item k
unsorted -> linear time
sorted -> logarithmic time using binary search -> compare k to B[n/2], divide and conquer (great paradigm)

INSERTION SORT (O(n) steps in terms of key position)
for i = 1, 2, ...n
insert A[i] into sorted array A[0:i-1], insert it in the correct position
by pairwise swaps down to the correct position
5 2 4 6 1 3
  |
starts with the index 1 (key) — swap 1x

2 5 4 6 1 3 
    |
  swap 1x

2 4 5 6 1 3
      |
  do nothing

2 4 5 6 1 3   
        |
      swap 4x

1 2 4 5 6 3
          |
        swap 3x
```

### References
[std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what)<br />
[A Tour of C++ (Second edition)](https://www.stroustrup.com/tour2.html) [Exercises](https://www.stroustrup.com/4thExercises.pdf)<br />
[The Design of C++ , lecture by Bjarne Stroustrup](https://www.youtube.com/watch?v=69edOm889V4)<br />
[Bjarne Stroustrup - The Essence of C++](https://www.youtube.com/watch?v=ZXc_z1sNbfA)<br />
[C Programming Tutorial 21 - Int, Float, and Double Data Types](https://www.youtube.com/watch?v=heULTdxf_yQ)<br />
[Casting in C++](https://www.youtube.com/watch?v=pWZS1MtxI-A)<br />
[A Tour of C++, page 39 — static_cast, page 161 — 14.2.4 Casts](https://elhacker.info/manuales/Lenguajes%20de%20Programacion/C++/A%20Tour%20of%20C++%20-%20Bjarne%20Stroustrup%20(Addison-Wesley,%202014)(193p).pdf)
[Dynamic Arrays in C++ (std::vector)](https://www.youtube.com/watch?v=HcESuwmlHEY)<br />
[Stacks and Queues Shopping List Exercise - C++ Tutorial 30](https://www.youtube.com/watch?v=6Ea980Vg8UA)<br />
[Scott Meyers - Effective Modern C++ part 1](https://www.youtube.com/watch?v=fhM24zs1MFA&list=PLmxXlAVb5hkyq5njldMEPYdOqTAQPLChR)<br />
[Reverse Polish Notation and The Stack - Computerphile](https://www.youtube.com/watch?v=7ha78yWRDlE)
[Lecture 3: Insertion Sort, Merge Sort](https://www.youtube.com/watch?v=Kg4bqzAqRBM)
[MIT OpenCourseWare — Introduction to Algorithms](https://ocw.mit.edu/courses/6-006-introduction-to-algorithms-fall-2011/video_galleries/lecture-videos/)

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
| **range-for loop** | | |
| **Containers** | `vector, list, forward list, map, unordered map` | A Class with the main purpose of holding objects is commonly called a container. **Standard template library:** a library of container types, the whole library is templated — the data type is up to you to decide, meaning, the user must provide the data type for the data structure. `std::vector` dynamic array that can grow in size, `std::list` doubly linked list, `std::deque` double ended queue, `std::set` an ordered set of unique elements, `std::map` ordered associative container that stores key-value pairs. ![Screenshot 2025-01-21 at 15 51 28](https://github.com/user-attachments/assets/05b3e26d-33ef-4c1e-8247-4575b132b9e2) |
| **vector** | `vector<double> v4(32, 9.9);` | A sequence of elements of a given type, store contiguously in memory. Meaning: it is an **dynamic array**, possible to resize everytime you add a new element. When we define a vector, we give it an initial size (initial number of elements). `vector<int> v1 = {1, 2, 3, 4};` `vector<string> v2; // size is 0` `vector<Shape*> v3(23); // size is 23, initial element is NULL` `vector<double> v4(32, 9.9); // size is 32, initial element is 9.9`. One of the most useful operations on a vector is `push_back()`, which adds a new element at the end increasing its size by one. _Reminder: iterate/use reference as argument for avoiding multiple vector copies._ **VECTOR MANAGES ITS OWN MEMORY, NO NEW OR DELETE**. |
| **iterator** | `typename T::iterator` | Object to traverse a container, uniform way to access elements in different types of containers even if the underlying data structures are different. Flexibility: Iterators can traverse containers that do not support random access (e.g., linked lists). Provide bounds checking that direct indexing may not. |
| **sort** | `std::sort algorithm` | Sort with random access containers, e.g.: std::vector: `std::sort(vec.begin(), vec.end());`. Sort member function with std::list: `lst.sort()`. |
| **De Morgan's laws** | `not (A or B) = (not A) and (not B)` | Read more [here](https://en.wikipedia.org/wiki/De_Morgan%27s_laws). |
| **container adaptors** | `stack<T>` | The standard library provides container adaptors `queue<T>`, `stack<T>`, and `priority_queue<T>`. A container adapter is a class template in the C++ Standard Library that provides a specific interface for a container by using another container type as its underlying storage. The container adapter modifies or restricts the interface of the underlying container to provide a different abstraction. Read more [here](https://en.cppreference.com/w/cpp/container/stack/stack). **Abstraction:** `std::stack` provides a stack interface (LIFO - Last In, First Out) by restricting the operations of the underlying container. It only exposes push, pop, top, and size-related operations, hiding other operations of the underlying container (underlying container: by default it is a `std::deque` Double Ended Queue... data structure in which you can append in either side, very similar to a vector). |
| **LIFO** | `Last In, First Out` | <img width="565" alt="Screenshot 2025-01-22 at 21 57 01" src="https://github.com/user-attachments/assets/05cad8ae-d6e8-4e68-a9b6-d2bb3dcd62a1" /> |
| **find_last_not_of** | `date = date.substr(0, date.find_last_not_of(" \t\n\r\f\v") + 1);` | Member function of the std::string class. It is used to find the last character in the string that is not one of the characters specified in the given set. Useful for trimming trailing characters from a string. `size_t find_last_not_of(const std::string& str, size_t pos = std::string::npos) const;` **str:** a string containing the characters to be excluded. **pos:** the position to start the search from. The default value is std::string::npos, which means the search starts from the end of the string. |
| **reverse polish notation** | `a b +` | Usually, operators come in between operands `a + b`: infix use. Prefix notation: `+ a b` `add(a, b)`. Postfix notation `a b +`, called reverse polish notation (because of its mathematician creator Jan Łukasiewicz). It saves the interpreter or compiler a lot of time and effort in order to execute the expressions. Imagine the C compiler to assembly code: store values of a and b in memory, before they can be added together, they must be lifted into the central processor unit (CPU) and when they are added it call the arimathic unit inside the CPU. So, in summary, GET A INTO A REGISTER, GET B INTO A REGISTER, AND DO THE ADDITION. Check online calculator [here](https://paodayag.dev/reverse-polish-notation-js-parser/). |
| **Precedence** | Check [here](https://en.cppreference.com/w/cpp/language/operator_precedence) | Multiply takes precedence (stronger operator). So, `a + b * c`, multiplication is done first. If you want the addition to go first, add parenthesis `(a + b) * c`. Now, transfering this thought to RPN> `a + b * c => a b c * +` operator will be applied to the imediate two preceding operands `(a + b) * c => a b + c *` |
| **Stack** | `LIFO` | Last thing in first thing out storage mechanism, popping a stack (top). Push operands to the stack (a b c). If you hit an operator, think how many operands does this got then take them off the stack. Do de operation and push the answer back (b * c = d). Push the final answer and leave it at the top of the stack (a + d). |


Merge sort - divide and conquer

Recurrence solving
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
[std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what) <br />
**CPP00 - CPP01** <br />
[A Tour of C++ (Second edition)](https://www.stroustrup.com/tour2.html) [Exercises](https://www.stroustrup.com/4thExercises.pdf) <br />
**CPP02** <br />
[Ep 018: Introduction to Floating-Point Binary and IEEE-754 Notation](https://www.youtube.com/watch?v=bFLchKMm6YA) <br />
[Understanding and Using Floating Point Numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point.html) <br />
[Floating point number representation](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_representation.html) <br />
[Printing floating point numbers](https://www.cprogramming.com/tutorial/floating_point/understanding_floating_point_printing.html) <br />
[Introduction to Fixed Point Number Representation](https://inst.eecs.berkeley.edu/~cs61c/sp06/handout/fixedpt.html) <br />
[Floating Point Numbers - Computerphile](https://www.youtube.com/watch?v=PZRI1IfStY0) <br />

## Concepts

| Task | Prototype | Description |
|:----|:-----:|:--------|
| **try catch** | `try throw catch` | When an error occurs, C++ will throw an exception. **try** defines a block of code to be tested for errors, **throw** throws an exception when a problem is detected, **catch** defines a block of code to be executed, if an error occurs in the try block. It will use throw for the tailored message. |
| **ellipsis** | `catch(...)` | If you don't know the **throw** type used in the **try** block, ellipsis notation can be applied for handling any type of exception. |
| **what** | `const char* what() const throw {}` | No parameters, pointer to a null terminated string with explanatory information about the error. Valid until the exception object from which is obtained is destroyed or a non-const member function on the exception object is called. [std::exception](https://en.cppreference.com/w/cpp/error/exception), [std::exception::what](https://en.cppreference.com/w/cpp/error/exception/what), **EXCEPTION IS AN OBJECT**, `what()` returns an explanatory string. |

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
### Reference Printing floating point numbers
```c
#include <ieee754.h>
#define LOG2_10 3.321928095
 
#define flt_zero(x) (fabs(x) < EPSILON)
 
int max_digs_rt = 3;  /* maximum # of 0's right of decimal before using
                         scientific notation */
int max_digs_lf = 5;  /* max # of digits left of decimal */
 
void print_real(double r, int width, int dec)
{
    int mag;
    double fpart, temp;
    char format[8];
    char num_format[3] = {'l',0,0};
    union ieee754_double *dl;
 
    dl = (union ieee754_double*)&r;
    mag = (dl->ieee.exponent - IEEE754_DOUBLE_BIAS) / LOG2_10;
    if (r == 0)
        mag = 0;
    if ((mag > max_digs_lf-1) || (mag < -max_digs_rt)) {
        num_format[1] = 'e';
        temp = r/pow(10, mag);      /* see if number will have a decimal */
        fpart = temp - floor(temp); /* when written in scientific notation */
    }
    else {
        num_format[1] = 'f';
        fpart = r - floor(r);
    }
    if (flt_zero(fpart))
        dec = 0;
    if (width == 0) {
        snprintf(format, 8, "%%.%d%s", dec, num_format);
    }
    else {
        snprintf(format, 8, "%%%d.%d%s", width, dec, num_format);
    }
    printf(format, r);
}
```

## Create a virtual machine with Multipass

To run this project on Linux from a different OS, I'm using Multipass to create a virtual machine. Follow these steps to set it up:
1. Download or upgrade multipass with HomeBrew
   ```bash
   brew install multipass
   brew upgrade multipass
   multipass version
   ```
3. Launch a Virtual Machine
- Customize your virtual machine during launch by specifying options like the Ubuntu release (--release), CPU count (--cpus), memory size (--mem), etc.
   ```bash
   multipass launch --name my-vm
   ```
4. Access the Virtual Machine
   ```bash
   multipass shell my-vm
   multipass list
   ```
5. Stop or delete the Virtual Machine
   ```bash
   multipass stop my-vm
   multipass delete my-vm
   ```
6. Create a SSH connection
- To speed up the process of linking the new instance with the SSH key from the previous step, we will use a little bit of cloud-init -> Copy and paste the below text into a file called vscode.yaml. Replace <public key> with the key found in id_rsa.pub, generated in an earlier step
  ```bash
    groups:
    - vscode
  runcmd:
    - adduser ubuntu vscode
  ssh_authorized_keys:
    - ssh-rsa <public key>
  ```
- Next, open a terminal in the same location as this file, and launch a new instance referencing this cloud-init file:
  ```bash
    multipass launch --cloud-init vscode.yaml
    multipass launch -n new-instance -d 20G --cloud-init vscode.yaml [specific name and specific size]
  ```
- Install SSH Server (if not installed): Ensure that SSH server is installed on your virtual machine. On Ubuntu, you can install it with:
  ```bash
  sudo apt update
  sudo apt install openssh-server
  ```
- Check SSH Service Status: Verify that SSH service is running on the virtual machine:
  ```bash
  sudo systemctl status ssh
  ```
  <img width="563" alt="Screenshot 2024-04-22 at 11 52 49" src="https://github.com/shinckel/CPP_projects-from-00-to-04/assets/115558344/972b9e2d-ae23-49c5-953f-b6f2c2e8b70f">
- Determine the IP address of your virtual machine: `multipass list` -> 192.168.64.17
- Generate SSH keys to authenticate communication between the VM and host `ssh-keygen -t rsa` -> host machine
- Download VSCode extension `Remote - SSH`
- In VSCode, click on `Open a Remote Window` -> Connect to Host -> Add New SSH Host... -> ssh ubuntu@192.168.64.17
- It will generate a new entry in config file
  ```bash
  Include /Users/hincksof/.colima/ssh_config

  Host 192.168.64.17
    HostName 192.168.64.17
    User ubuntu
    IdentityFile /Users/hincksof/ubuntu_config/.ssh/id_rsa


  Host 192.168.64.13
    HostName 192.168.64.13
    User ubuntu
    IdentityFile /Users/hincksof/ubuntu_config/.ssh/id_rsa
  ```
- At this point, VSCode will ask you for the location of your SSH keys. The default location should be in a hidden directory named “.ssh” in the home directory.
- ` IdentityFile` is the place where it is stored the public key generated previously in yout host machine ->  `ssh-keygen -t rsa`

### References
[Using Multipass with vscode](https://discourse.ubuntu.com/t/using-multipass-with-vscode/34905)

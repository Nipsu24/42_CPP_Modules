<h1 align="center">CPP Modules</h1>

> Hive Helsinki (School 42) 12th curriculum project (Rank04)

<h2 align="center">
	<a href="#about">About</a>
	<span> · </span>
	<a href="#modules">Modules</a>
	<span> · </span>
	<a href="#requirements">Requirements</a>
	<span> · </span>
	<a href="#instructions">Instructions</a>
</h2>

## About
The repository contains several modules consisting of different exercises related to the basics of C++ programming.

## Modules
<details>
  <summary>CPP00</summary>
	
  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp00/ex00)
    - familiarizes with basic C++ concepts such as **string** class, related functions and **cout**.
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp00/ex01)
    - introduces **classes** initialization, **cin** object of isstream class and further string manipulation and
      formatting possibilities such as **.substr()**, **.setw()**, and **.length()**.
      Additionally **try / catch** statements are used.
    - Sets up a phone book by initialising a class 'PhoneBook', containing 8 classes of contacts 
    - user has options between the 3 commands ```ADD```, ```SEARCH``` and ```EXIT``` which respectively
      adds contacts (and their details), searches for contacts (first displays entire list of contacts,
      then by entering index shows contact details) or exits the phone book
    - in case of invalid input, errors are displayed to the user
  
</details>

<details>
  <summary>CPP01</summary>
  
 - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex00)
    - introduces **new** for allocating memory for a class
    - learning about initialising classes on heap vs. stack
 - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex01)
    - learning about array of classes using new for memory allocation
 - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex02)
    - introduces concept of **references**
 - [**ex03**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex03)
    - reference vs. pointer to a class
    - object which contains pointer to a class can be initialised without explicitly
      assigning value to the class whereby reference requires the object of the class
      not to be empty
 - [**ex04**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex04)
    - introduces concepts of **ifstream** and **ofstream**
    - further string manipulation such as **.find()**, **.erase()**, **.insert()**
    - user can give 3 arguments to the program (file name, string1 and string2),
      the content of the file given to the program is copied into another created
      file and then the sequence of string2 replaces sequence of string1 (if existing),
      prints errors in case of invalid arguments
 - [**ex05**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex05)
    - introduces concept of **function pointers** in C++
 - [**ex06**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp01/ex06)
    - introduces concept of **switch** statements
  
</details>

<details>
  <summary>CPP02</summary>

  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp02/ex00)
    - set up of classes in **orthodox canonical form**
    - learning about copy constructor and copy-assignment constructor
    - fixed point vs floating point vs integer representation
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp02/ex01)
    - introduces concept of **operator overloading**
  - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp02/ex02)
    - further operator overloading for <, >, !=, ==, >=, <=, ++, -- 
  
</details>

<details>
  <summary>CPP03</summary>

  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp03/ex00)
    - sets up class for learning about inheritance in later exercises
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp03/ex01)
    - introduces concept of inheritance of classes
    - initialisation of derived class, which inherits functions and members of base class
    - as exercise requires, derived class member variables are initialised with different values
    - **virtual function** and **function override** used in order to create unique behaviour
      of derived class function 'attack'
    - additionally uses **typeid** in order to determine if base or derived class object called
      particular function for custom behaviour
  - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp03/ex02)
    - same as above, further derived class with different values of the member variables is created
  
</details>

<details>
  <summary>CPP04</summary>

  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp04/ex00)
    - sets up base class and two derived classes
    - uses virtal functions and override in order to alter behaviour of derived classes' functions
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp04/ex01)
    - derived classes contain member variable to another class
    - copy constructor creates deep copies of respective derived classes
  - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp04/ex02)
    - same as above, but base class is made abstract by declaring pure virtual function
  
</details>

<details>
  <summary>CPP05</summary>

  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp05/ex00)
    - introduces concept of throwing and catching exceptions
    - try/catch blocks handle situations where class object is initiated with out of bounce variables
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp05/ex01)
    - further class introduced which utilises individual custom exceptions 
  - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp05/ex02)
    - abstract class and child classes which inherit exceptions from base class
  - [**ex03**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp05/ex03)
    - exception handling in addition to memory allocation
    - nested try/catch blocks to prevent memory leaks
  
</details>

<details>
  <summary>CPP06</summary>

  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp06/ex00)
    - introduces concept of static casting in C++
    - program takes string as argument and converts if possible into char, int, float and double
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp06/ex01)
    - uses reinterpret_cast in order to serialize and deserialize / cast between different datatypes
  - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp06/ex02)
    - function that uses randomizer in order to create one out of three derrived class objects
    - introduces concept of dynamic casting from base to derived classes (both pointer and references)
    - uses this to identify the derived class object to which base object pointer is pointing
  
</details>

<details>
  <summary>CPP07</summary>

  - [**ex00**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp07/ex00)
    - introduces concept function templates
    - swap, min and max function template implementation
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp07/ex01)
    - implementation of iter function template, taking array pointer, array length and function pointer
  - [**ex02**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp07/ex02)
    - implementation of array class template, compatible with different array data types
    - handling of [] operator and throwing exceptions in case of out-of-bounds indexing
  
</details>


## Requirements
-`c++` compiler

## Instructions

### 1. Compiling the respective executables

To compile the executables of the different exercises, cd into the 
exercise folder in question and run:

```
$ make
```

### 2. Cleaning all binary (.o) and executable files

To delete all files generated with make, run:
```
$ make fclean
```

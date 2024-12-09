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
    - Familiarizes with basic C++ concepts such as **string** class, related functions and **cout**.
  - [**ex01**:](https://github.com/Nipsu24/42_CPP_Modules/tree/main/cpp00/ex01)
    - Introduces **classes** initialization, **cin** object of isstream class and further string manipulation and
      formatting possibilities such as **.substr()**, **.setw()**, and **.length()**.
    - Sets up a phone book by initialising a class 'PhoneBook', containing 8 classes of contacts 
    - user has options between the 3 commands ```ADD```, ```SEARCH``` and ```EXIT``` which respectively
      adds contacts (and their details), searches for contacts (first displays entire list of contacts,
      then by entering index shows contact details) or exits the phone book
    - in case of invalid input, errors are displayed to the user
  
</details>

<details>
  <summary>CPP01</summary>
  
  Description and exercises for the CPP01 module go here.
  
</details>

<details>
  <summary>CPP02</summary>
  
  Description and exercises for the CPP02 module go here.
  
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

### 2. Cleaning all binary (.o) and executable files (.a)

To delete all files generated with make, run:
```
$ make fclean
```

# COMPILER-DESIGN-BASICS

*COMPANY* : CODTECH IT SOLUTIONS

*NAME* : VANKAPATI DEEPAK JAYA RAM YADAV

*INTERN ID* : CT08DN1557

*DOMAIN NAME* : C++ PROGRAMMING

*DURATION* : 8 WEEKS

*MENTOR* : NEELA SANTOSH

# Simple Arithmetic Expression Compiler (SCD.cpp)

This is a command-line C++ application that parses and evaluates arithmetic expressions entered by the user. It supports standard mathematical operations and parentheses, mimicking the behavior of a basic calculator.

## Features

- Supports addition (`+`), subtraction (`-`), multiplication (`*`), and division (`/`)
- Handles nested expressions using parentheses
- Gracefully handles invalid input with error messages
- Detects and prevents division by zero

## Getting Started

### Prerequisites

- A C++ compiler that supports C++11 or later (e.g., g++, clang++)
- A terminal or command prompt to run the executable

### Compilation

To compile the code using `g++`, run:

```bash
g++ SCD.cpp -o SCD
````

### Running the Program

After compiling, execute the program using:

```bash
./SCD
```

### Usage

Once the program starts, you can input arithmetic expressions directly:

```
Simple Arithmetic Expression Compiler
Enter expressions to evaluate (or 'exit' to quit)
> 3 + 5 * (2 - 1)
Result: 8
> (10 + 2) / 4
Result: 3
> exit
```

### Example Expressions

* `3 + 4 * 2`
* `(1 + 2) * (3 + 4)`
* `-5 + 3`
* `10 / (2 + 3)`

### Error Handling

The program will output meaningful error messages for:

* Invalid input (e.g., `3 +`)
* Division by zero
* Mismatched parentheses

## File Structure

```
SCD.cpp      # Source file containing the main logic and parser
README.md    # Documentation for using the compiler
```

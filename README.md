# Linear Algebra Calculator

C++ Program I made for a high school assignment. I used test driven development (TDD) to test each of my functions.

## Screenshot of Project

## About Project:
#### This project completes two useful calculations:
- Calculates determinants for nxn matrices using recursion
- Solves linear systems

I made this project implementing mathematical algorithms in C++ to get experience with writing unit tests

## How it Works:
This project solves systems of linear equations in the form Ax = b, where A is the coefficient matrix, x represents the unknown varibale, and b represents the constants.

#### The program separates these calculations into several functions
- GetA() reads dimensions and values of the matrix provided by the user
- Getb() reads constant values of the system of equations
- Det() uses recursion to calculate the determinant of a matrix
- Minor() removes the first row of and a specific column of a matrix to create a smaller matrix
- Replace() replaces a specific colunn of a matrix with the constants vector
- Solvex() calculates the determinants of the modified matrices created by the Minor() function
- Display() prints the matrix or solution vector, displaying it in the terminal

## Challenges:
Writing the unit tests was my greatest challenge in this project, since it was my first time using a testing framework. I started by separating out all the calculations steps into individual functions From there, I had to figure out how the different source files worked together.

I used lin-algebra.cc to implement the functions and main.cc to run the actual calculator. I then made seperate testing files to check all the functions in lin-algebra.cc to debug easier.

I wrote tests for the matrix minors, column replacement, calculations of the determinants, and for solving linear systems using the CppUnit framework.

Separating everything into smaller functions and testing each individually made debugging and catching errors early on way more efficient without having to run the entire calculator every time.

This project gave me experience with unit testing, organizing components into separate programs for clarity, and implementing multiple programs across files.

## Future Improvements:
- providing clearer prompts for the user to enter matrix dimensions and values
- allow users to calculate determinants independently without solving an entire system as some systems are quite large
- supporting 1x1 matrices
- improving efficiency when solving floating-point calculations

## How to Run It
#### Requirements:
- C++ compiler
- Make
- CppUnit (for running tests - not necessary if you only want to use the calculator)

1. Launch Calculator Program
   ./lin-algebra

2. Enter a System fo Equations
   example:
   5x + 2y = 11
   x - y = 1.5

4. Enter Your Matrix
   example:
   2 2 - meaning 2 rows, 2 columns
   5 2 - first row of coefficents
   1 -1 - secodn row of coefficients
   11 1.5 - constants vector

6. Receive an Output:
   in this case the result is:
   2.00 0.50 - meaning x = 2.00 and y = 0.50

8. Run the Tests (optional)
   If you have CppUnit installed you can compile and run the CppUnit tests in the test h files with:
   make test

## Resources Used:
- C++
- CppUnit
- GNU Make
- Test-driven development

# Sorting and Searching Algorithms

This project has been done during **Software Engineering studies** at **ALX** powered by **Holberton School**. It aims to learn about sorting and searching algorithms and developed in **C language**.

## Technologies
* C files are compiled using `gcc 9.4.0`
* Tested on Ubuntu 20.04 LTS

## Files
All of the following programs are written in C:

## Usage
To build the project, you need to compile it using the following command:
```bash
gcc -Wall -Wextra -Werror -pedantic -std=gnu89 main.c sorting_algorithms/*.c searching_algorithms/*.c utils/*.c -o main -lm
```
and here's a breakdown of the command:
* gcc: The GNU Compiler Collection version 9.4.0, used to compile this C program.
* -Wall -Wextra -Werror -pedantic: These options enable various compiler warnings and treat them as errors to enforce strict code quality.
* -std=gnu89: Specifies the standard to which the code should conform, in this case, GNU89.
* main.c: The main source file that contains the main function.
* sorting_algorithms/*.c: All C source files for the sorting algorithms.
* searching_algorithms/*.c: All C source files for the searching algorithms.
* utils/*.c: All C source files in the utils directory.
* -o main: Specifies the output file name, which will be main.
* -lm: Links the math library, which is necessary for mathematical functions like sqrt.

After compiling the program, you can run it with the following command:
```bash
./main
```

## Authors
* [**Ammar Noor**](https://www.linkedin.com/in/ammar-noor/)

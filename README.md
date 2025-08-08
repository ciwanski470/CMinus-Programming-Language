# Bad C Compiler

## Description
This is a C99 Compiler that I am making for educational purposes, learning about compilers and low-level programming.
There is no use case for this compiler over GCC or Clang, as there is no preprocessor or linker (so it can only be used on a single file).
It would also run slower than GCC and Clang and produce less-optimized assembly (obviously).
It is a fun project, though.

## Installation
I dunno man just download the repo and compile it yourself if you wanna use it for whatever reason. Be careful as there is a GNU extension in "ast_printer.c" (##\_\_VA_ARGS__). Other than that just run make and then execute main. There is no command line tool for this because it's not a reliable (or even viable) tool in the first place.

## Usage Instructions
Compile it yourself and then execute main.

## Features
1. Properly lexes the given program, consuming comments
2. Generates an AST
3. Prints the AST to an output file called "output.ast" in an Indented Tree (or a similar) format
4. Segmentation Fault
5. That's all I did so far

## Technologies Used
The code is written entirely in C.

Uses Flex and Bison to generate code for the files "scanner.c", "parser.h", and "parser.c".

Uses Makefile to make the program easy to compile

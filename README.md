# The C- Programming Language

## Description
C- is a programming language that is just C (specifically C99), but worse in just about every way.
It is made for educational purposes for me to learn about compiler construction and low-level programming through C.
There is no use case for this compiler over GCC or Clang, as there is no preprocessor or standard library.
It is also less optimized than GCC and Clang (obviously).

## Installation
Why would you want to install this?

## Usage Instructions
Compile it yourself and then run "./main \[filename\]"

## Features
* Properly lexes the given program, consuming comments
* Generates an AST
* Prints the AST to an output file called "output.ast" in an Indented Tree format
* Accurately (I think) reports errors (although does not tell you where those errors are)
* Generates LLVM

## Features not available in this implementation
* Backwards compatibility with old K&R C features.
Namely, the K&R function definition (nobody uses this) and implicit return type
* Variable-length arrays (C11 standard says I don't have to (I just don't want to implement this))
* In the C99 standard, inline is a compiler suggestion and does not always have to be followed.
This compiler will read the user's suggestion and make the conscious decision to ignore it.
* Initializer lists will just throw an error because I don't feel like implementing them for now.
* You may not specify a global's linkage. In fact, the 'static' keyword does not exist in C-
* Flexible array members are not allowed because no

## Technologies Used
* Code is most written in C, but also uses C++ for LLVM.
* Flex and Bison used to generate code for the files "scanner.c", "parser.h", and "parser.c".
* LLVM C++ API used to generate IR and lower into assembly.
* Makefile used to make the program easy to compile.

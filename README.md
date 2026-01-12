# The C- Programming Language

## Description
C- is a programming language that is just C (specifically C99), but worse in just about every way.
It is made for educational purposes for me to learn about compiler construction and low-level programming through C.
There is no use case for this compiler over GCC or Clang, as there is no preprocessor or standard library.
It is also less optimized than GCC and Clang (obviously).

I probably should've chosen an easier language to implement for my first ever exploration of the subject, but hey, we gotta stay ambitious.

## Installation
Why would you want to install this?

## Usage Instructions
* Compile it yourself and then run "./main \[filename\]".
* This generates an object file that you'll have to link manually using something like clang.
* Don't worry about the target machine language. If it runs, the machine code should be valid.
* You can give the executable a different name by modifying the Makefile.

## Features
* Properly lexes the given program, consuming comments
* Generates an AST
* Prints the AST to an output file called "output.ast" in an Indented Tree format
* Accurately (I think) reports errors (although does not tell you where those errors are)
* Generates LLVM
* Lowers LLVM into an object file
* You can compare pointer to float/double

## Features not available in this implementation
* Backwards compatibility with old K&R C features. Namely, the K&R function definition (nobody uses this) and implicit return types.
* Variable-length arrays (C11 standard says I don't have to (I just don't want to implement this)).
* In the C99 standard, inline is a compiler suggestion and does not always have to be followed.
This compiler will read the user's suggestion and make the conscious decision to ignore it (I believe it doesn't matter anyway because of LLVM optimizations).
* Initializer lists will just throw an error because I don't feel like implementing them for now.
* Structs and unions are not available because of special cases like self-referential structs (such as a linked list) not being completed properly during semantic analysis.
Changing the way I handle struct types to fix this issue is very invasive and I don't feel like it's worth doing for this project. They will parse, but then throw an error.
Technically, you can still do anything structs allow you to do, except you'll have to use arrays, malloc, and/or pointer arithmetic.
* Flexible array members are not allowed because I said so.

## Technologies Used
* Code is most written in C, but also uses C++ for LLVM.
* Flex and Bison used to generate code for the files "scanner.c", "parser.h", and "parser.c".
* LLVM C++ API used to generate IR and lower into assembly.
* Makefile used to make the program easy to compile.

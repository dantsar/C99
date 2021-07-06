# The Cooper Union C Compiler (CUCC)
This is my work for ECE466: Compilers, a graduate level class where I had to build a C compiler using Flex and Bison. The target language was x86, and lexical analysis, semantic analysis, IR generation, and assembly generation was handled.  The C ISO was consulted **extensively**.

# Dependencies 
* CMake (v. 3.14)
* GCC 
* Make (*optional*)
* Flex
* Bison

# Usage
To manually build and compile the compiler from source, run:
```
mkdir -p build
cd build
cmake ..
make
```
or if you want to save a few keystrokes, use the Makefile provided by running:

```
make
```

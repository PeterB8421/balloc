# balloc
C library which provides a single function - `balloc()`,
a function used to allocate a single byte on the heap.

It is also possible to link a C++ executable against the library.
The `balloc.h` header file supports both C and C++.

To be more precise, if C++ is detected, the header tells the
compiler not to mangle the function name using C++ name mangling
rules, but rather use C's minimalistic mangling, which in turn
allows the linker to properly link the `balloc `library compiled
using a C compiler.

## Build

```sh
cmake .
make
```

## Usage

Make sure to include the header file in your C/C++ code.

```c
#include <balloc.h>
```

To allocate one byte, simply call the `balloc()` function.

```c
uint8_t * byte = balloc();
```

Make sure to properly specify paths to the header file
and shared object file if they are located in a directory
where the compiler and linker don't usually look.

```sh
-L path/to/folder/with/balloc/  # Compiler flag to specify library location
-I path/to/folder/with/header/  # Compiler flag to specify header location
```

Do not forget to link the library when invoking the compiler.

```sh
-lballoc
```

If you do not have the shared object file installed,
specify the directory where the `.so` is located
when launching your binary.

```sh
LD_LIBRARY_PATH=path/to/so/ ./my-binary
```

## Installation

```sh
sudo cp include/balloc.h /usr/include
sudo cp libballoc.so /usr/lib
```

Alternatively, you can move/copy the files to directories
`usr/local/include` and `usr/local/lib`.

Or you can avoid performing a system-wide installation altogether,
just make sure to properly specify link directory (`-L` flag)
and include directory (`-I` flag) when invoking the compiler.
You will also have to set the `LD_LIBRARY_PATH` variable when
running your binary which links against the `balloc` library
to tell the linker where the `.so` file is located.

As of now, it is not possible to install the library using
a package manager (eg. `pacman`, `zypper`).

## Test

### Link against the balloc library and call balloc() from C++

```sh
cd test/
g++ test.cpp -std=c++11 -I ../include/ -L ../ -lballoc -o test-cpp
LD_LIBRARY_PATH=.. ./test-cpp
```

### Link against the balloc library and call balloc() from C

```sh
cd test/
gcc test.c -std=c99 -I ../include/ -L ../ -lballoc -o test-c
LD_LIBRARY_PATH=.. ./test-c
```


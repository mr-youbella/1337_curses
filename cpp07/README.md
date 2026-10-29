# C++ Module 07

Generic functions and an owning array class, with implementations kept in headers so templates can be instantiated by callers.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Interface |
| --- | --- | --- |
| [ex00](ex00/) | `templates` | `swap`, `min`, and `max` for compatible types. |
| [ex01](ex01/) | `iter` | Applies a function to every element of an array. |
| [ex02](ex02/) | `array` | `Array<T>` with allocation, copying, indexing, and a bounds exception. |

`whatever.hpp` defines the three function templates; the demo uses integers, strings, and floats. `min` and `max` return a const reference and select the second argument when the values compare equal.

`iter.hpp` has overloads for mutable arrays with `T&` callbacks and const arrays with `const T&` callbacks. Its demo prints arrays, mutates integer elements, and visits a const array.

`Array<T>` owns an allocation created with `new[]`. Sized construction value-initializes elements; copying allocates separate storage and copies each value. Both const and mutable indexing reject negative indices and indices at or beyond `size()` by throwing `OutOfBounds`.

## Build and run

Each exercise has a Makefile using `c++ -Wall -Wextra -Werror -std=c++98`.

```bash
make -C ex00
./ex00/templates
make -C ex01
./ex01/iter
make -C ex02
./ex02/array
```

No executable takes arguments. The array main fills 750 elements with random integers, checks them against a separate allocation, constructs copies, and catches two out-of-range accesses. Values vary with the random seed.

## Checks and organization

The important implementations are [whatever.hpp](ex00/whatever.hpp), [iter.hpp](ex01/iter.hpp), and [Array.hpp](ex02/Array.hpp). Each `main.cpp` is a small exercise driver. Additional useful cases for the array are zero size, self-assignment, and access through a const instance.

Builds are independent. Use `make -C exNN clean`, `fclean`, or `re` for the selected exercise.

[Project subject](../Subjects/cpp07.subject.pdf)

[← cpp06](../cpp06/README.md) · [1337 Curses](../README.md) · [cpp08 →](../cpp08/README.md)

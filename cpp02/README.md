# C++ Module 02

A fixed-point number class grows from raw storage into an arithmetic type, then feeds a point-in-triangle exercise.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Implementation |
| --- | --- | --- |
| [ex00](ex00/) | `fixed` | Constructors, assignment, destruction, and raw-bit access. |
| [ex01](ex01/) | `fixedPoint` | Integer/float conversion and stream insertion. |
| [ex02](ex02/) | `fixedPoint` | Comparisons, arithmetic, increments/decrements, and `min`/`max`. |
| [ex03](ex03/) | `bsp` | Immutable point coordinates and a triangle-area containment test. |

## Numeric representation

`Fixed` uses an integer with eight fractional bits. Integer construction shifts by eight; float construction scales by 256 and rounds with `roundf`. Conversion reverses that scale. Arithmetic operators in the later exercises calculate through `float` and construct another `Fixed` result. Increment and decrement change the raw value by one, corresponding to a step of 1/256.

The geometry function computes the triangle's area and three subareas after converting point coordinates to floats. It rejects zero subareas, excluding points on edges, and compares the area sum with the original area. Despite the exercise name, this is an area-based containment test, not a spatial partition tree.

## Build and run

The Makefiles use `c++ -Wall -Wextra -Werror -std=c++98`.

```bash
make -C ex00
./ex00/fixed
make -C ex01
./ex01/fixedPoint
make -C ex02
./ex02/fixedPoint
```

All supplied mains use fixed examples without command-line arguments.

**Current `ex03` build issue:** [bsp.cpp](ex03/bsp.cpp) contains a stray `s` after `return false;`. As checked in, `make -C ex03` fails. The declared executable is `bsp`; after that source issue is corrected, its demo is run with `./ex03/bsp`.

## Checks and limits

The mains show copying, conversion, and selected arithmetic/comparison operations. Useful additional cases include fractional values, increment step size, and triangle vertices or edges. The arithmetic implementation has no explicit division-by-zero check, and floating-point area equality has precision limits.

The exercises are separate snapshots of `Fixed`, so a change to one directory does not update the others. Their Makefiles provide `clean`, `fclean`, and `re`.

[Project subject](../Subjects/cpp02.subject.pdf)

[← cpp01](../cpp01/README.md) · [1337 Curses](../README.md) · [cpp03 →](../cpp03/README.md)

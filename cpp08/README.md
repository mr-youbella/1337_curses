# C++ Module 08

Containers, iterators, and algorithms, including an iterable adaptation of `std::stack`.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Implementation |
| --- | --- | --- |
| [ex00](ex00/) | `easyfind` | A function template wrapping `std::find`, with an exception for a missing value. |
| [ex01](ex01/) | `span` | A capacity-limited integer collection with shortest/longest distance queries. |
| [ex02](ex02/) | `MutantStack` | Stack operations plus forward and reverse iterators. |

`easyfind` returns the matching container iterator, so callers can use the result directly. Its demo searches a vector and a list, including an unsuccessful vector search.

`Span` stores values in a vector and accepts either individual numbers or an iterator range. A shortest-span query sorts a copy and scans adjacent differences, preserving the stored order. The longest span subtracts the minimum from the maximum. Both queries require at least two values, and insertion checks the configured capacity. Subtraction widens to `long` before calculating the difference.

`MutantStack<T>` derives from `std::stack<T>` and exposes iterators from its protected underlying container. It supplies mutable/const forward and reverse iteration while retaining normal `push`, `pop`, `top`, and `size` operations.

## Build and run

Make and a C++ compiler are required. All three Makefiles use `-std=c++98 -Wall -Wextra -Werror`.

```bash
make -C ex00
./ex00/easyfind
make -C ex01
./ex01/span
make -C ex02
./ex02/MutantStack
```

The mains take no arguments. `span` includes the five-value example and a range insertion of 10,000 even numbers. `MutantStack` runs corresponding stack and list iteration examples for comparison.

## Checks

Use the supplied mains to inspect successful/missing searches, span calculations, and iteration order. Further cases include an empty or single-value span, exceeding capacity, and reverse traversal of a const `MutantStack`. These demonstrations are not a separate testing framework or a benchmark claim.

The template implementations live in `easyfind.hpp` and `MutantStack.hpp`; `Span` is split between its header and source. Each exercise provides `clean`, `fclean`, and `re`.

[Project subject](../Subjects/cpp08.subject.pdf)

[← cpp07](../cpp07/README.md) · [1337 Curses](../README.md) · [cpp09 →](../cpp09/README.md)

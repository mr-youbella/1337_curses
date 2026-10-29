# C++ Module 06

Three different reasons to cast: scalar conversion, a pointer/integer round trip, and identifying a dynamic type.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Approach |
| --- | --- | --- |
| [ex00](ex00/) | `convert` | Parses a scalar literal and prints `char`, `int`, `float`, and `double` representations. |
| [ex01](ex01/) | `serializer` | Uses `reinterpret_cast` between `Data*` and `uintptr_t`. |
| [ex02](ex02/) | `identify` | Uses `dynamic_cast` to distinguish `A`, `B`, and `C` through `Base`. |

The scalar converter recognizes single-character literals, decimal numeric forms, and pseudo-literals such as `nan`, `nanf`, and signed infinities. It reports non-displayable characters and impossible conversions. The parser is specific to these forms; it does not handle C++ expression syntax or scientific notation.

The serializer converts a pointer's representation rather than storing the object's contents. The returned integer only serves to recover a pointer while the original object remains alive; it is not a persistent file format.

The identification exercise generates one of three derived types. Pointer casts return null on a mismatch, while reference casts are tried inside exception handlers. `Base` has a virtual destructor, and identification does not use `typeid`.

## Build and usage

Build each exercise separately with Make and a compiler accepting `-std=c++98 -Wall -Wextra -Werror`. The `ex00` Makefile also enables AddressSanitizer and debug information (`-fsanitize=address -g`).

```bash
make -C ex00
./ex00/convert 42
./ex00/convert 42.0f
./ex00/convert nan
make -C ex01
./ex01/serializer
make -C ex02
./ex02/identify
```

`convert` takes exactly one argument. The other two mains run without arguments: the serializer shows pointer equality after the round trip, and the identifier prints the detected type through both interfaces. Pointer addresses and the generated type vary between runs.

## Checks

Try a printable character, a non-displayable numeric character code, a negative value, and an invalid literal with `convert`. The included serializer and identification mains provide their own demonstrations; there is no separate test runner.

Each exercise's `clean`, `fclean`, and `re` targets manage its own build files.

[Project subject](../Subjects/cpp06.subject.pdf)

[← cpp05](../cpp05/README.md) · [1337 Curses](../README.md) · [cpp07 →](../cpp07/README.md)

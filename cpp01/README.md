# C++ Module 01

Object lifetime, references, and file streams, explored through small programs with different ownership rules.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Focus |
| --- | --- | --- |
| [ex00](ex00/) | `zombie` | A local zombie and a dynamically allocated zombie, with explicit deletion. |
| [ex01](ex01/) | `zombieHorde` | An array allocated with `new[]` and released with `delete[]`; the demo creates 13 zombies. |
| [ex02](ex02/) | `brain` | Prints the addresses and values of a string, a pointer, and a reference. |
| [ex03](ex03/) | `weapon` | A required weapon reference in `HumanA` and an optional weapon pointer in `HumanB`. |
| [ex04](ex04/) | `sed` | Replaces occurrences of a string and writes `<filename>.replace`. |
| [ex05](ex05/) | `harl` | Dispatches complaint levels through pointers to member functions. |
| [ex06](ex06/) | `harlFilter` | Uses switch fallthrough to print a selected level and all higher levels. |

The replacement program loads the file into a string, finds each occurrence, and rebuilds the surrounding substrings. It advances past inserted text, so replacement text containing the search string is not repeatedly replaced. An empty search string is rejected.

## Build and usage

Each exercise builds separately with Make and `c++ -Wall -Wextra -Werror -std=c++98`.

```bash
make -C ex00
./ex00/zombie
make -C ex04
printf 'hello 1337\n' > ex04/sample.txt
./ex04/sed ex04/sample.txt hello hi
cat ex04/sample.txt.replace
make -C ex06
./ex06/harlFilter WARNING
```

The replacement example writes `hi 1337` followed by a newline. `harlFilter WARNING` prints the warning and error sections. Its recognized levels are `DEBUG`, `INFO`, `WARNING`, and `ERROR`.

For the remaining demos, build the corresponding `exNN` directory and run the executable listed above without arguments. `ex05`'s main calls `INFO` and `ERROR` directly; it is not a command-line level selector.

## Checks

The exercise mains are the included demonstrations. For `sed`, try an absent search string, adjacent matches, an empty replacement, and a missing input file. Compare `HumanA`'s reference with `HumanB`'s pointer to see how the class interfaces express whether a weapon is required.

Each exercise supports `clean`, `fclean`, and `re` through its Makefile.

[Project subject](../Subjects/cpp01.subject.pdf)

[← cpp00](../cpp00/README.md) · [1337 Curses](../README.md) · [cpp02 →](../cpp02/README.md)

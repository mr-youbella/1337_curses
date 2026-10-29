# C++ Module 00

Three first steps into C++: stream output, an interactive phonebook, and a class with shared account statistics.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | What it does |
| --- | --- | --- |
| [ex00](ex00/) | `megaphone` | Converts command-line text to uppercase using stream output. |
| [ex01](ex01/) | `phonebook` | Stores up to eight contacts and provides `ADD`, `SEARCH`, and `EXIT`. |
| [ex02](ex02/) | `account` | Runs the supplied account driver against `Account.cpp`. |

The phonebook keeps contacts in a fixed array. After the eighth contact, insertion wraps around and replaces older entries. Search presents shortened name columns and accepts a one-based index to display the full contact. Empty fields are rejected during entry.

`Account` separates per-account balances and transaction counts from static totals shared by the class. The driver creates accounts, makes deposits, tries withdrawals, and prints status with timestamps. Withdrawals exceeding the balance are refused.

## Build and run

Each exercise has an independent Makefile using `c++ -std=c++98 -Wall -Wextra -Werror`. Run these commands from the module directory:

```bash
make -C ex00
./ex00/megaphone "hello, 1337"
make -C ex01
./ex01/phonebook
make -C ex02
./ex02/account
```

The megaphone separates arguments with spaces and includes a trailing space. With no text it prints its feedback message and returns a nonzero status.

## Checks

Try adding a ninth phonebook contact, entering an empty field, and searching for an invalid index. `ex02/tests.cpp` is the bundled account exercise driver; timestamps vary between runs, so compare balance and transaction fields rather than entire output lines. There is no reference log in this checkout.

Use `make -C ex00 clean`, `fclean`, or `re` for object cleanup, full cleanup, or rebuilding; the same targets exist in the other exercises.

[Project subject](../Subjects/cpp00.subject.pdf)

[1337 Curses](../README.md) · [cpp01 →](../cpp01/README.md)

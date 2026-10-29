# C++ Module 09

Three command-line programs built around different containers: dated lookup, postfix evaluation, and merge-insertion-style sorting.

[Repository](../README.md) · **C++98** · **Score: 100**

## Programs

| Directory | Executable | Container use |
| --- | --- | --- |
| [ex00](ex00/) | `btc` | An ordered map of dates to exchange rates. |
| [ex01](ex01/) | `RPN` | A stack of integer operands. |
| [ex02](ex02/) | `PmergeMe` | Sorting with both `std::vector` and `std::deque`. |

Each directory has an independent Makefile using `c++ -std=c++98 -Wall -Wextra -Werror`.

## Bitcoin Exchange

`btc` loads [ex00/data.csv](ex00/data.csv) and processes a text file beginning with `date | value`. Each following record uses a `YYYY-MM-DD` date and the separator ` | `. An ordered-map `lower_bound` lookup selects the exact date or the nearest earlier stored rate, then multiplies it by the input amount.

Run from `ex00/`, since the database filename is relative to the working directory:

```bash
make -C ex00
cd ex00
printf 'date | value\n2011-01-03 | 2\n2011-01-09 | 1.5\n' > input.txt
./btc input.txt
cd ..
```

The code checks date structure and calendar days, requires years from 2009 onward, and rejects negative amounts and values above 1000. Its date validator currently indexes the month-length array before rejecting an out-of-range month, so malformed month values remain an implementation limitation.

## Reverse Polish Notation

`RPN` reads one quoted expression, splits it on whitespace, and pushes single-digit operands. An operator pops the right operand and then the left, evaluates, and pushes the result. The final stack must contain exactly one value.

```bash
make -C ex01
./ex01/RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
```

This example prints `42`. Operators are `+`, `-`, `*`, and `/`, with integer division. Invalid tokens, missing operands, division by zero, or leftover operands print `Error`. Multi-digit and signed input operands are not accepted; intermediate results can exceed one digit.

## PmergeMe

The sorter accepts positive integers within `int` range, including space-separated values inside quoted arguments. It forms ordered pairs, sorts pairs by their larger member, and builds a main chain from those larger values. Smaller values are inserted with `std::lower_bound` in a Jacobsthal-derived order; a fallback inserts any skipped entries, followed by an unpaired final value.

```bash
make -C ex02
./ex02/PmergeMe 3 5 9 7 4
```

The program prints the input, the sorted vector, and separately measured sort times for vector and deque in microseconds. Pair ordering uses nested loops rather than recursive Ford–Johnson sorting, and binary insertion searches the whole main chain. Those details matter when assessing its complexity or comparison count. No fixed timing or optimality result is claimed.

## Checks and cleanup

Try an absent date between database entries with `btc`, invalid or incomplete expressions with `RPN`, and sorted, reverse-sorted, duplicate-containing, and odd-length inputs with `PmergeMe`. Neither sorter timings nor one successful run substitute for correctness checks on both container paths.

Use `clean`, `fclean`, and `re` in each exercise. They do not remove input files created for manual checks.

[Project subject](../Subjects/cpp09.subject.pdf)

[← cpp08](../cpp08/README.md) · [1337 Curses](../README.md)

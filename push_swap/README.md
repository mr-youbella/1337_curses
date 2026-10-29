# push_swap

Sort integers by emitting operations on two linked-list stacks.

[Repository](../README.md) · **C / sorting** · **Score: 125**

## Sorting strategy

The program starts with the input in stack A and an empty stack B. It prints the moves needed to leave A in ascending order. Parsing accepts separate arguments and space-separated numbers inside an argument, then checks numeric syntax, signed integer bounds, and duplicates. Already sorted input produces no moves.

The implementation chooses its strategy by input size:

- Two and three values use direct comparisons and short operation sequences.
- Four and five values move low-ranked values to B, sort the remaining three, and push the saved values back.
- Larger inputs first assign each value a rank. Values move to B through a sliding rank window of 20 for inputs up to 100 values, or 35 for larger inputs. The largest remaining rank is then rotated to the top of B using the nearer direction and pushed back to A.

The sorter emits `sa`, `pa`, `pb`, `ra`, `rb`, `rra`, and `rrb`. The bonus checker also accepts the other standard stack operations, including simultaneous swaps and rotations.

## Build and usage

Use Make and a C compiler; compilation enables `-Wall -Wextra -Werror`.

```bash
make
./push_swap 3 2 1
./push_swap "9 -4 0 7 2"
make bonus
./push_swap 3 2 1 | ./checker 3 2 1
```

`push_swap` writes one operation per line. `checker` reads operations from standard input until EOF, replays them, and prints `OK` when A is sorted and B is empty, or `KO` otherwise. Invalid numbers or operations produce `Error`.

To supply moves by hand:

```bash
printf 'sa\n' | ./checker 2 1
```

That sequence produces `OK`. With an interactive checker, press Ctrl-D to finish entering operations.

## Source layout

| Path | Responsibility |
| --- | --- |
| [mandatory/push_swap.c](mandatory/push_swap.c) | Input checks, rank assignment, and strategy selection |
| [mandatory/small_sort.c](mandatory/small_sort.c) | Small-input cases |
| [mandatory/big_sort.c](mandatory/big_sort.c) | Rank-window distribution and maximum-first reconstruction |
| `mandatory/operations_*.c` | Stack manipulation and emitted instructions |
| [bonus/](bonus/) | Input validation, instruction reading, and the checker |

## Checking results

Use the same input on both sides of the sorter/checker pipeline. Try sorted and reverse-sorted inputs, negative values, duplicate values, and values outside the `int` range. Count output lines to inspect move counts; no benchmark results or optimality claim are recorded here.

The parser uses several eight-byte pointer allocation assumptions, and the checker relies on `OPEN_MAX`; this checkout is oriented toward the original 64-bit macOS environment.

`make clean` removes objects; `make fclean` removes the binaries too; `make re` rebuilds `push_swap`.

[Project subject](../Subjects/push_swap.subject.pdf) · [Back to 1337 Curses](../README.md)

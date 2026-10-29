# libft

A small C library for working with memory, strings, file descriptors, and linked lists.

[Repository](../README.md) · **C** · **Score: 125**

## Overview

`libft.a` collects the utility functions that later projects build on. The interface lives in [libft.h](libft.h); each function has its own source file, making the implementation easy to inspect or reuse.

| Area | Included functions |
| --- | --- |
| Characters | Classification, case conversion, and ASCII checks |
| Memory | `ft_memset`, `ft_bzero`, `ft_memcpy`, `ft_memmove`, `ft_memchr`, `ft_memcmp`, `ft_calloc` |
| Strings | Length, copying, comparison, searching, duplication, substrings, joining, trimming, and splitting |
| Conversion and output | `ft_atoi`, `ft_itoa`, and character/string/integer output to a file descriptor |
| Bonus | Creation, insertion, traversal, mapping, and cleanup of singly linked lists |

## Build and use

Run from this directory with Make and a C compiler. The Makefile uses `cc -Wall -Wextra -Werror`. The header includes macOS's `<libc.h>`, so the checkout is not directly portable to every Unix system.

```bash
make           # Core functions in libft.a
make bonus     # Add linked-list functions to the archive
```

Include the header in a caller and link the archive after the caller's source or object files:

```c
#include "libft.h"

int main(void)
{
    ft_putendl_fd("Hello, 1337", 1);
    return (0);
}
```

For a caller saved as `example.c` in this directory:

```bash
cc -Wall -Wextra -Werror -I. example.c libft.a -o example
./example
```

`make clean` removes objects; `make fclean` also removes the archive; `make re` rebuilds the core library.

## Implementation notes

- `ft_memmove` copies backward when the destination follows the source, preserving overlapping data.
- `ft_calloc` checks multiplication overflow before allocating and zeroing memory.
- `ft_split` counts words first, allocates separate strings, and cleans up earlier strings if an allocation fails. Its pointer-array allocation assumes eight-byte pointers.
- List nodes store `void *` content. Cleanup takes a caller-supplied destructor; `ft_lstmap` uses it to release a partially constructed result on failure.

The library allocates results for functions such as `ft_strdup`, `ft_substr`, and `ft_split`. The caller owns those results and must free them, including each string in a split array.

## Checking the library

There is no standalone test runner here. Useful caller-side checks include overlapping `ft_memmove` ranges, empty and delimiter-only strings for `ft_split`, allocation boundaries, and list cleanup with dynamically allocated content.

[Project subject](../Subjects/libft.subject.pdf) · [Back to 1337 Curses](../README.md)

# get_next_line

Read a file descriptor one line at a time without discarding bytes from the next line.

[Repository](../README.md) · **C** · **Score: 125**

## Interface and state

```c
char *get_next_line(int fd);
```

Each call returns an allocated line, including its newline when present. The final line can end at EOF without a newline. A `NULL` result ends iteration and can also indicate an invalid descriptor or an allocation failure. Free every returned line.

The mandatory version keeps one static remainder. The bonus version uses a static `OPEN_MAX`-sized array to keep separate remainders for different descriptors. Both versions default to a `BUFFER_SIZE` of 42, overridable at compilation.

The read helper appends chunks to the saved text, the extraction helper separates the first line, and the remaining suffix is kept for the next call. Because concatenation reallocates and copies accumulated text, this implementation does not promise constant-time processing per chunk.

## Compile with a caller

There is no Makefile or executable in this directory. Compile the reader together with your own program. The headers depend on `OPEN_MAX` from the platform's headers; the checked-in version builds on macOS.

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 -I. \
    example.c get_next_line.c get_next_line_utils.c -o read_lines
./read_lines
```

A minimal `example.c` reading standard input:

```c
#include "get_next_line.h"

int main(void)
{
    char *line;

    while ((line = get_next_line(0)) != NULL)
    {
        write(1, line, ft_strlen(line));
        free(line);
    }
    return (0);
}
```

To use the bonus, include `get_next_line_bonus.h` instead and compile `get_next_line_bonus.c` with `get_next_line_utils_bonus.c`. Select one implementation per executable; both define the same function names.

## Checks and boundaries

Try an empty file, a single newline, a line longer than the buffer, and a last line without a newline. Rebuild with buffer sizes such as 1 and 42. A bonus caller can alternate reads between two open files to check descriptor-specific state.

The bonus array is indexed by the descriptor. Its guard currently permits `fd == OPEN_MAX`, which is outside that array; valid use requires `0 <= fd < OPEN_MAX`. There is no automated test runner in this directory.

[Project subject](../Subjects/get_next_line.subject.pdf) · [Back to 1337 Curses](../README.md)

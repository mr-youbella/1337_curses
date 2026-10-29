# minitalk

A client sends text to a server using only Unix user signals.

[Repository](../README.md) · **C / POSIX signals** · **Score: 125**

## The protocol

The server prints its PID and waits in `pause()`. The client encodes each byte most-significant bit first: `SIGUSR1` represents one and `SIGUSR2` represents zero. After eight signals, the server has a byte to print.

`sigaction` supplies the sender PID. If it changes, the server resets its partial-character state. This tracks one active sender rather than maintaining independent streams for concurrent clients. The client spaces signals with `usleep(100)`; there is no acknowledgment for each bit.

| Version | Behavior |
| --- | --- |
| Mandatory | Sends the message followed by a newline; the server prints reconstructed bytes. |
| Bonus | Groups one- to four-byte UTF-8 sequences and sends a `SIGUSR2` acknowledgment when a terminating null byte arrives. |

The bonus client installs a handler that prints `Message received.` on acknowledgment, but exits after sending rather than waiting explicitly for that reply.

## Build and run

Use Make and a C compiler on a Unix-like system with `sigaction`, `kill`, and `usleep`.

```bash
make
./server
```

In another terminal, use the PID printed by the server in place of `12345`:

```bash
./client 12345 "Hello from 1337"
```

Build and run the bonus pair separately:

```bash
make bonus
./server_bonus
```

```bash
./client_bonus 12345 "Hello, 世界"
```

Use the PID from `server_bonus` for the last command. Stop either server with Ctrl-C. Run one client at a time.

## Layout and checks

[mandatory/](mandatory/) and [bonus/](bonus/) each contain their client, server, headers, and small numeric/output helpers. `make clean` removes objects, `make fclean` also removes all four binaries, and `make re` rebuilds the mandatory pair.

For manual checks, send a short message, a longer quoted string, and several messages in succession. Use valid UTF-8 for the Unicode bonus; the byte-counting code is not a full UTF-8 validator. These are manual checks, with no bundled test script.

[Project subject](../Subjects/minitalk.subject.pdf) · [Back to 1337 Curses](../README.md)

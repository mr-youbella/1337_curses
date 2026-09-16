*This project has been created as part of the curriculum by [youbella](https://profile.intra.42.fr/users/youbella), [wkannouf](https://profile.intra.42.fr/users/wkannouf).*

# ft_irc

This is our IRC server written in C++98. The goal was to understand how an IRC server works: accepting clients, reading commands, sending replies, and managing channels without blocking the other users.

## Description

The server uses one `poll()` loop and non-blocking sockets. Clients can register, join channels, send private messages, and use the channel operator commands required by the subject.

## Instructions

Build the project:

```bash
make
```

Start the server with a port and password:

```bash
./ircserv 6667 testpass
```

To remove object files, use `make clean`. To remove the executable too, use `make fclean`. `make re` rebuilds everything.

### Testing with nc

In another terminal, connect with:

```bash
nc 127.0.0.1 6667
```

Then type:

```text
PASS testpass
NICK alice
USER alice 0 * :Alice
JOIN #general
PING hello
```

The server should answer:

```text
PONG :hello
```

Open another `nc` client, register another nickname, and join `#general` to test messages between users.

## Commands

The server handles:

```text
PASS    NICK    USER    PING    QUIT
JOIN    PART    PRIVMSG
KICK    INVITE  TOPIC   MODE
```

Channel modes available in this project are:

```text
+i / -i        invite-only channel
+t / -t        only operators can change the topic
+k <key> / -k  set or remove a channel key
+o <nick>      give or remove operator status
+l <limit>     set or remove the user limit
```

`JOIN #one,#two` is supported. The simple combined modes `+it` and `-it` are also supported.

There is also a small bot in channels. Messages starting with `!` can be used with:

```text
!help
!time
!dice 20
!users
!topic
!ping
```

## Resources

- [RFC 2811](https://datatracker.ietf.org/doc/html/rfc2811)
- [RFC 2812](https://datatracker.ietf.org/doc/html/rfc2812)
- [Beej's Guide to Network Programming](https://beej.us/guide/bgnet/)
- The ft_irc subject provided by 42

## AI Usage

We used AI as a helper while reviewing the code, thinking about test cases.

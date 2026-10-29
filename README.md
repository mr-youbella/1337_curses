<div align="center">

# 1337 Curses

**My projects at 1337 · 42 Network**

C foundations, Unix systems, graphics, networking, and the C++98 modules.

![Youbella's 42 stats](https://badge.mediaplus.ma/black/Youbella)

[Projects](#projects) · [Technical skills](#technical-skills) · [Getting started](#getting-started)

</div>

## About this repository

This is my collection of projects from the 1337 / 42 curriculum. It starts with a C utility library and grows into interactive programs: a shell, a raycasting engine, an IRC server, and a containerized WordPress stack.

Implemented projects have their own READMEs explaining the code, build requirements, and usage. The [Subjects](Subjects/) directory holds the accompanying project PDFs. Born2beroot has a subject-based overview, and `ft_transcendence` is currently in progress with its subject included here.

[minishell](minishell/), [cub3D](cub3D/), [ft_irc](ft_irc/), and [ft_transcendence](ft_transcendence/) are team projects. Their guides identify that shared work; implementation details are based on the source available in this collection.

## Projects

Scores below preserve the evaluations recorded in this portfolio. They describe the evaluated projects, rather than guaranteeing that every target builds unchanged on every machine. Project READMEs note platform requirements and known checkout limitations.

### C foundations

| Project | Description | Score |
| --- | --- | ---: |
| [libft](libft/) | Memory, string, character, and linked-list utilities in a static C library. | 125 |
| [ft_printf](ft_printf/) | Variadic formatted output with conversion helpers and selected bonus flags. | 110 |
| [get_next_line](get_next_line/) | Buffered line reading, with separate file-descriptor state in the bonus. | 125 |

### Algorithms and synchronization

| Project | Description | Score |
| --- | --- | ---: |
| [push_swap](push_swap/) | Two-stack sorting with rank windows, small-input routines, and a checker. | 125 |
| [philosophers](philosophers/) | Dining philosophers with pthread mutexes and a process/semaphore bonus version. | 125 |

### Unix and system programming

| Project | Description | Score |
| --- | --- | ---: |
| [minitalk](minitalk/) | Client/server text transmission through Unix signals, with a Unicode bonus. | 125 |
| [minishell](minishell/) | Team project: interactive shell with builtins, quoting, expansion, pipes, and redirections. | 101 |

### Graphics and games

| Project | Description | Score |
| --- | --- | ---: |
| [so_long](so_long/) | MiniLibX tile game with map validation, collectibles, and animated bonus hazards. | 125 |
| [cub3D](cub3D/) | Team project: MLX42 raycaster with textured walls, a minimap, doors, and animated overlays. | 125 |

### Networking and infrastructure

| Project | Description | Score |
| --- | --- | ---: |
| [Born2beroot](Born2beroot/) | Linux server administration in a VM; subject and overview included, without the VM or configuration. | 125 |
| [netPractice](netPractice/) | Ten saved IPv4 addressing and routing exercises with the supplied simulator. | 100 |
| [ft_irc](ft_irc/) | Team project: C++98 IRC server with non-blocking sockets, channel modes, and a bot. | 125 |
| [inception](inception/) | Docker Compose stack for WordPress, MariaDB, NGINX, and five bonus services. | 125 |

### Web applications — in progress

| Project | Description | Status |
| --- | --- | --- |
| [ft_transcendence](ft_transcendence/) | Team web application project; subject and overview available while development continues. | In progress |

### C++ modules

Each module contains independently built exercises. Their READMEs form a linked series from basic classes to container-based programs.

| Module | Focus | Score |
| --- | --- | ---: |
| [cpp00](cpp00/) | Streams, classes, a phonebook, and static account state. | 100 |
| [cpp01](cpp01/) | Object lifetime, pointers/references, file streams, and member-function pointers. | 100 |
| [cpp02](cpp02/) | Fixed-point representation, operator overloads, and a geometry exercise. | 100 |
| [cpp03](cpp03/) | Inheritance, constructor order, and a virtual-base diamond. | 100 |
| [cpp04](cpp04/) | Polymorphism, deep copying, abstract classes, and cloneable objects. | 100 |
| [cpp05](cpp05/) | Exceptions, grade-checked forms, and a form factory. | 100 |
| [cpp06](cpp06/) | Scalar casts, pointer serialization, and runtime type identification. | 100 |
| [cpp07](cpp07/) | Function templates, array iteration, and an owning array template. | 100 |
| [cpp08](cpp08/) | Containers, iterators, spans, and an iterable stack adapter. | 100 |
| [cpp09](cpp09/) | Dated map lookup, reverse Polish notation, and sorting across containers. | 100 |

### Other recorded evaluations

These exam results are retained from the original project index. Exam source code is not included in this repository.

| Evaluation | Score |
| --- | ---: |
| Exam Rank 02 | 100 |
| Exam Rank 03 | 100 |
| Exam Rank 04 | 100 |
| Exam Rank 05 | 100 |

## Technical skills

| Area | Represented in the code |
| --- | --- |
| C and memory | Allocation, ownership, pointer operations, static libraries, linked lists, and variadic functions |
| Algorithms | Rank-based sorting, stack operations, flood fill, DDA ray traversal, and binary insertion |
| Unix systems | Signals, file descriptors, processes, pipes, redirections, threads, mutexes, and semaphores |
| Graphics | MiniLibX, MLX42, texture sampling, sprite animation, input handling, and collision checks |
| C++98 | Classes, inheritance, virtual dispatch, exceptions, casts, templates, STL containers, and iterators |
| Networking and deployment | IPv4 subnetting, routes, TCP sockets, `poll`, Docker Compose, NGINX, PHP-FPM, MariaDB, and Redis |

## Repository structure

```text
1337_curses/
├── README.md
├── Subjects/          Project subject PDFs
├── Born2beroot/       Subject-based overview; VM/configuration not included
├── libft/             Reusable C foundations
├── ft_printf/
├── get_next_line/
├── minitalk/          Unix signals and shell/process projects
├── minishell/
├── philosophers/
├── push_swap/         Stack sorting
├── so_long/           2D and first-person graphics
├── cub3D/
├── netPractice/       Network configurations and supplied simulator
├── ft_irc/            IRC server
├── inception/         Container configuration and service guides
├── ft_transcendence/  In-progress team project; overview only
└── cpp00/ … cpp09/    C++ modules, each divided into exNN directories
```

## Getting started

```bash
git clone https://github.com/mr-youbella/1337_curses.git
cd 1337_curses
```

Choose a project from the tables and read its README before building. There is no repository-wide build target: most C programs have local Makefiles, Philosophers builds in two subdirectories, C++ exercises build individually, and `get_next_line` is compiled with a caller. netPractice opens in a browser; Inception starts through Docker Compose.

Born2beroot and `ft_transcendence` currently provide documentation and subject references in this collection, with no runnable project files.

Several projects retain their original macOS setup, including graphics framework links, Homebrew library paths, or platform-specific headers. Inception's supplied storage paths target a Linux VM. The individual guides describe those requirements alongside the relevant commands.

---

Portfolio maintained by [mr-youbella](https://github.com/mr-youbella) · 1337 / 42 Network

# C++ Module 03

An inheritance hierarchy built around ClapTrap, ending in a diamond with a shared virtual base.

[Repository](../README.md) · **C++98** · **Score: 100**

## Class progression

| Directory | Executable | Added behavior |
| --- | --- | --- |
| [ex00](ex00/) | `claptrap` | Tracks hit points, energy, damage, attacks, and repairs. |
| [ex01](ex01/) | `scavtrap` | Derives `ScavTrap` from `ClapTrap`, with its own attack and `guardGate`. |
| [ex02](ex02/) | `fragtrap` | Adds `FragTrap` and `highFivesGuys`. |
| [ex03](ex03/) | `diamondtrap` | Combines both derived classes and exposes `whoAmI`. |

Constructor and destructor messages make the lifetime order visible in each demonstration. The early mains repeatedly attack, take damage, and try repairs to exercise the object's hit-point and energy state.

In `ex03`, both `ScavTrap` and `FragTrap` virtually inherit `ClapTrap`. `DiamondTrap` explicitly initializes that shared base, keeps its own name alongside the base's `_clap_name` name, and forwards `attack` to `ScavTrap`. `whoAmI` prints both identities. The demo also calls both inherited special methods and assigns one diamond object to another.

## Build and run

Make and a C++ compiler are required. Each exercise uses `-std=c++98 -Wall -Wextra -Werror` and has its own Makefile.

```bash
make -C ex00
./ex00/claptrap
make -C ex01
./ex01/scavtrap
make -C ex02
./ex02/fragtrap
make -C ex03
./ex03/diamondtrap
```

These are scripted object demonstrations; none takes arguments or starts an interactive game.

## Reading and checking the hierarchy

Start with each exercise's `main.cpp`, then inspect the class headers and constructor initializer lists. Compare construction/destruction order in `ex01` with `ex03`, and inspect `whoAmI` before and after assignment. The class-state examples are local to each exercise; there is no shared library or separate automated test framework.

Each exercise supports `clean`, `fclean`, and `re`.

[Project subject](../Subjects/cpp03.subject.pdf)

[← cpp02](../cpp02/README.md) · [1337 Curses](../README.md) · [cpp04 →](../cpp04/README.md)

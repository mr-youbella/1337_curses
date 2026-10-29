# C++ Module 04

Runtime polymorphism and ownership: animal hierarchies first, then cloneable objects behind abstract interfaces.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Focus |
| --- | --- | --- |
| [ex00](ex00/) | `animal` | Virtual `makeSound` dispatch, contrasted with non-virtual dispatch in `WrongAnimal`. |
| [ex01](ex01/) | `brain` | Cats and dogs own dynamically allocated `Brain` objects with 100 string slots. |
| [ex02](ex02/) | `brain` | Makes `Animal` abstract through a pure virtual `makeSound`. |
| [ex03](ex03/) | `materia` | `AMateria`, `Ice`, `Cure`, characters, and a prototype source. |

## Ownership and copying

The animal hierarchy has a virtual destructor so derived objects can be deleted through base pointers. Cat and dog copy operations allocate a separate `Brain` instead of sharing the source pointer. The mains create mixed animal arrays and exercise copying and cleanup.

The Materia exercise uses `ICharacter` and `IMateriaSource` as pure abstract interfaces. `MateriaSource` stores clones of up to four prototypes and creates further clones by type. `Character` has four inventory slots and clones its inventory when copied. Equipping stores the supplied pointer, so ownership matters at the call site.

**Implementation detail:** this version's `Character::unequip` deletes the item before clearing its slot. The supplied subject asks for unequipping without deleting it; callers should understand the actual behavior before retaining an item pointer.

## Build and run

Each exercise uses `c++ -Wall -Wextra -Werror -std=c++98` and builds independently.

```bash
make -C ex00
./ex00/animal
make -C ex01
./ex01/brain
make -C ex02
./ex02/brain
make -C ex03
./ex03/materia
```

All mains run without arguments. The last one demonstrates learning prototypes, creating and equipping Materia, using them on another character, and handling invalid or empty inventory slots.

## Checks

Compare `Animal*` and `WrongAnimal*` sound calls in `ex00`. Read the allocation and copy paths in `Cat.cpp` and `Dog.cpp` to follow deep copying. For Materia, inspect the distinction between a cloned prototype and an inventory pointer, including what happens during `unequip` and destruction.

The included mains are demonstrations rather than a complete ownership test suite. Make targets `clean`, `fclean`, and `re` are available in each exercise.

[Project subject](../Subjects/cpp04.subject.pdf)

[← cpp03](../cpp03/README.md) · [1337 Curses](../README.md) · [cpp05 →](../cpp05/README.md)

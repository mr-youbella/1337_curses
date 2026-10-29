# C++ Module 05

Exceptions and abstract classes expressed as a small bureaucracy: grades, signatures, execution permissions, and a form factory.

[Repository](../README.md) · **C++98** · **Score: 100**

## Exercises

| Directory | Executable | Progression |
| --- | --- | --- |
| [ex00](ex00/) | `bureaucrat` | Grade bounds, increment/decrement, and custom exceptions. |
| [ex01](ex01/) | `form` | A form's signature state and minimum signing/execution grades. |
| [ex02](ex02/) | `Aform` | Abstract executable forms: shrubbery, robotomy, and presidential pardon. |
| [ex03](ex03/) | `intern` | Creates concrete forms from a requested form name. |

A bureaucrat's grade runs from 1 to 150; a lower number means more authority. Construction and grade changes throw when those bounds are crossed. Signing checks authority against the form's required grade. Concrete execution methods check both the signature and the executor's grade.

## Concrete forms

| Form | Sign / execute grade | Effect |
| --- | --- | --- |
| `ShrubberyCreationForm` | 145 / 137 | Writes an ASCII tree to `<target>_shrubbery`. |
| `RobotomyRequestForm` | 72 / 45 | Prints drilling and success/failure messages. |
| `PresidentialPardonForm` | 25 / 5 | Prints a pardon message for the target. |

Robotomy chooses the first result randomly, then alternates a shared static flag between success and failure. It does not make an independent random choice on each execution.

`Intern::makeForm` recognizes `shrubbery creation`, `robotomy request`, and `presidential pardon`. It returns a newly allocated `AForm*`; the caller is responsible for deleting it. Unknown names throw the intern's custom exception.

## Build and run

Each Makefile uses `c++ -std=c++98 -Wall -Wextra -Werror`.

```bash
make -C ex00
./ex00/bureaucrat
make -C ex01
./ex01/form
make -C ex02
(cd ex02 && ./Aform)
make -C ex03
./ex03/intern
```

The executables run the hard-coded scenarios in their mains, with no arguments. `ex02` creates `Home_shrubbery` in its working directory, so the example runs it inside `ex02/`.

## Checks

The mains exercise grade boundaries, failed signing/execution, repeated robotomy, and factory-created forms. Inspect the `try`/`catch` blocks to see which layer reports a failure. Useful further cases include executing an unsigned form and requesting an unknown factory name.

All exercise Makefiles provide `clean`, `fclean`, and `re`. Generated shrubbery files are not removed by those targets.

[Project subject](../Subjects/cpp05.subject.pdf)

[← cpp04](../cpp04/README.md) · [1337 Curses](../README.md) · [cpp06 →](../cpp06/README.md)

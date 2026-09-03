# C++ Modules

10 projects (CPP00–CPP09) from the 42 curriculum, covering C++ from OOP basics through templates, STL containers, and memory management.

**Tech stack:** C++, Makefile, STL.

## Modules

### CPP00 — Introduction to C++
- Ex00: Megaphone — string manipulation, `std::string`.
- Ex01: Contact/PhoneBook — `class`, constructors, getters/setters.
- Ex02: Account — static members, function pointers.

### CPP01 — Classes & References
- Ex00: Zombie — classes, constructors, dynamic allocation, `new`/`delete`.
- Ex01: Zombie Horde — arrays of objects, pointer arithmetic.
- Ex02: HumanA/B — composition, references, `const` correctness.
- Ex03: Tactical Violence — inheritance basics.
- Ex04: Sed Anemic — code organization, separation of concerns.
- Ex05: Harl 2.0 — composition with `std::string`, function pointer tables.
- Ex06: Harl Filter — filtering levels at runtime.

### CPP02 — Operators & Fixed-Point
- Ex00: Fixed — `class` with const members, comparison operators.
- Ex01: Fixed — arithmetic operators, conversion to/from `int`/`float`.
- Ex02: Fixed — comparison operators as non-members.
- Ex03: Fixed + Point — operator overloading, `std::sqrt`.

### CPP03 — Inheritance & Polymorphism
- Ex00: ClapTrap — base class, constructors/destructors, member functions.
- Ex01: ScavTrap — inheritance, `virtual` functions.
- Ex02: FragTrap — multiple derived classes, exception handling (`std::exception`).

### CPP04 — Abstraction & Polymorphism
- Ex00: Animal — abstract base class, pure virtual functions.
- Ex01: Cat/Dog — derived classes, `Brain` composition.
- Ex02: Animal deep copy — copy constructors, pointer members.

### CPP05 — Polymorphism in Practice
- Ex00: Bureaucrat — exception classes, `throw`/`catch`, `const` exceptions.
- Ex01: Form — abstract form class, derived forms.
- Ex02: Executive Form — form hierarchy, runtime polymorphism.
- Ex03: Intern — factory pattern, `std::unique_ptr`-style ownership, form creation by name.

### CPP06 — Templates
- Ex00: ScalarConverter — function templates, template specialization, `typeid`.
- Ex01: Serializer — serialization/deserialization, `uintptr_t`, `reinterpret_cast`.
- Ex02: Array — class template, `const` correctness, iterators.

### CPP07 — Templates & Iterators
- Ex00: `easyfind` — function template for searching in containers.
- Ex01: `iter` — function template taking a callable.
- Ex02: Array v2 — template class with iterator support, deep copy.

### CPP08 — STL Containers
- Ex00: `std::stack` — RPN calculator using `std::stack`.
- Ex01: `Span` — storing integers, `shortestSpan`/`longestSpan` with STL algorithms.
- Ex02: `MutantStack` — inheriting from `std::stack`, iterator access.

### CPP09 — STL Algorithms & Containers
- Ex00: BitcoinExchange — file I/O, `std::map`, date parsing, exception handling.
- Ex01: RPN — expression evaluation with `std::stack`, operator precedence.
- Ex02: PmergeMe — merge-insert sort, `std::deque`/`std::vector`, performance benchmarking.

## What I learned

Moved from C to C++ across these 10 modules — learning the class model, inheritance and polymorphism, operator overloading, templates, and the STL. The biggest jumps: understanding when to use `virtual` and why (polymorphism, not just "it's a keyword"), getting comfortable with templates (function templates, class templates, specialization), and learning the STL containers and algorithms instead of rolling everything by hand. The PmergeMe project was where I actually *used* a sort algorithm on real data and measured the performance difference — that's where the abstract stuff became concrete.

## How to build

Each module has its own `Makefile`. Build an exercise like this:

```bash
cd cpp-module-04/ex00
make
./main
```

There's no top-level Makefile — build per-exercise.

## What's missing

No screenshots or outputs — these are console programs, so there's not much to show visually. Each exercise's `main.cpp` demonstrates the behavior if you want to run it.

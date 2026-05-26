*This activity has been created as part of the 42 curriculum by csodini, tsalland.*

# push_swap

## Description

`push_swap` is a sorting project based on two stacks, `a` and `b`, and a limited set of stack operations.

The goal is to receive a list of integers as arguments and print a sequence of operations that sorts stack `a` in ascending order, with the smallest value at the top.

At the beginning:

- stack `a` contains all input integers;
- stack `b` is empty;
- duplicate values are forbidden;
- all values must fit inside the range of a C `int`.

The program prints one operation per line and nothing else on `stdout`.

## Operations

The program can generate the following operations:

| Operation | Description |
|---|---|
| `sa` | Swap the first two elements of stack `a` |
| `sb` | Swap the first two elements of stack `b` |
| `ss` | `sa` and `sb` at the same time |
| `pa` | Push the first element of `b` to the top of `a` |
| `pb` | Push the first element of `a` to the top of `b` |
| `ra` | Rotate stack `a` upwards |
| `rb` | Rotate stack `b` upwards |
| `rr` | `ra` and `rb` at the same time |
| `rra` | Reverse rotate stack `a` |
| `rrb` | Reverse rotate stack `b` |
| `rrr` | `rra` and `rrb` at the same time |

## Instructions

### Compilation

```bash
make
```

This creates:

```bash
./push_swap
```

Other available rules:

```bash
make clean
make fclean
make re
```

### Execution

Basic usage:

```bash
./push_swap 4 67 3 87 23
```

Forced strategies:

```bash
./push_swap --simple 5 4 3 2 1
./push_swap --medium 5 4 3 2 1
./push_swap --complex 5 4 3 2 1
./push_swap --adaptive 5 4 3 2 1
```

If no strategy flag is provided, the program uses the adaptive strategy by default:

```bash
./push_swap 5 4 3 2 1
```

If no argument is provided, the program prints nothing and exits normally:

```bash
./push_swap
```

## Strategy flags

| Flag | Strategy | Complexity |
|---|---|---|
| `--simple` | Simple sorting strategy | `O(n^2)` |
| `--medium` | Chunk-based strategy | `O(n sqrt n)` |
| `--complex` | Binary radix strategy | `O(n log n)` |
| `--adaptive` | Strategy selected according to disorder | Depends on input |
| no flag | Adaptive strategy by default | Depends on input |

## Benchmark mode

The optional `--bench` flag prints additional information to `stderr`.

Example:

```bash
./push_swap --bench --adaptive 4 67 3 87 23
```

The benchmark output includes:

- computed disorder;
- selected strategy;
- theoretical complexity;
- total number of operations;
- count of each operation type.

Example:

```text
[bench] disorder: 40.00%
[bench] strategy: Adaptive / O(n sqrt n)
[bench] total_ops: 13
[bench] sa: 0 sb: 0 ss: 0 pa: 5 pb: 5
[bench] ra: 2 rb: 1 rr: 0 rra: 0 rrb: 0 rrr: 0
```

Operations are printed to `stdout`, while benchmark information is printed to `stderr`.

Example with a checker:

```bash
ARG="4 67 3 87 23"
./push_swap --bench $ARG 2> bench.txt | ./checker_linux $ARG
cat bench.txt
```

## Error handling

In case of error, the program prints:

```text
Error
```

to `stderr`.

Errors include:

- non-numeric arguments;
- duplicate values;
- values outside the range of a C `int`;
- malformed signs such as `++1`, `--1`, `+-1`;
- excessively long numeric strings.

Accepted examples:

```bash
./push_swap 1 2 3
./push_swap -1 0 42
./push_swap +1 -2 3
./push_swap 2147483647
./push_swap -2147483648
```

Rejected examples:

```bash
./push_swap 1 2 2
./push_swap one 2 3
./push_swap 2147483648
./push_swap -2147483649
./push_swap ++1
./push_swap --1
```

## Algorithms

### Simple strategy — `O(n^2)`

The simple strategy is a baseline sorting method.

It performs local stack operations until stack `a` becomes sorted. It is easy to understand and useful for small or low-disorder inputs, but its theoretical upper bound is quadratic.

### Medium strategy — `O(n sqrt n)`

The medium strategy is based on chunk sorting.

Values are first indexed, then divided into ranges. Elements are pushed from stack `a` to stack `b` chunk by chunk, then pushed back into `a` in sorted order.

Using chunks helps reduce the number of operations compared with a purely quadratic approach.

### Complex strategy — `O(n log n)`

The complex strategy uses binary radix sorting on indexed values.

Each value is normalized into an index, then sorted bit by bit. For each bit, the algorithm decides whether to push the value to stack `b` or rotate it inside stack `a`.

Since each pass processes all elements and the number of passes depends on the number of bits needed to represent the indexes, this strategy has a theoretical complexity of `O(n log n)` in the Push_swap operation model.

## Disorder metric

Before sorting, the program computes a disorder metric between `0` and `1`.

This metric is based on inverted pairs:

- `0` means the stack is already sorted;
- `1` means the stack is maximally disordered;
- values between `0` and `1` represent partially disordered inputs.

An inverted pair occurs when a larger value appears before a smaller value.

Example:

```text
3 1 2
```

The pairs `(3, 1)` and `(3, 2)` are inverted.

## Adaptive strategy

The adaptive strategy selects one of the implemented strategies according to the measured disorder.

| Disorder | Selected strategy | Complexity |
|---|---|---|
| `< 0.2` | Simple strategy | `O(n^2)` |
| `< 0.5` | Medium strategy | `O(n sqrt n)` |
| `>= 0.5` | Complex strategy | `O(n log n)` |

The adaptive mode is used as a selector between the three implemented strategies.

Low-disorder inputs are handled with the simple strategy, medium-disorder inputs with the chunk strategy, and high-disorder inputs with the radix strategy.

## Implementation notes

### Indexing

Some strategies work on indexes instead of raw integer values.

Example:

```text
values:   40 -10   7
indexes:   2   0   1
```

This allows the algorithms to work on a compact range from `0` to `n - 1`.

### Context structure

A `t_context` structure is used to group execution-related values such as the selected flag, benchmark flag, disorder value and benchmark counters.

This keeps function prototypes smaller and helps respect the 42 Norm.

### Memory management

Stacks are dynamically allocated and freed before the program exits.

Several allocation failure paths are protected so that already allocated memory can be cleaned when needed.

## Project structure

```text
.
├── Makefile
├── pushswap.h
├── pushswap.c
├── error.c
├── init.c
├── flag.c
├── bench.c
├── simple.c
├── medium.c
├── complex.c
├── operation_swap_push.c
├── operation_push_rotate.c
├── operation_rrotate.c
├── ft_printf.c
└── ft_print.c
```

## Testing

Useful manual tests:

```bash
make re
./push_swap
./push_swap 3 2 1
./push_swap +1 -2 3
./push_swap 2147483648
./push_swap -2147483649
```

With checker:

```bash
ARG="4 67 3 87 23"
./push_swap $ARG | ./checker_linux $ARG
```

Random tests:

```bash
ARG=$(shuf -i 0-9999 -n 100)
./push_swap $ARG | ./checker_linux $ARG

ARG=$(shuf -i 0-9999 -n 500)
./push_swap $ARG | ./checker_linux $ARG
```

Operation count:

```bash
ARG=$(shuf -i 0-9999 -n 500)
./push_swap $ARG | wc -l
```

Benchmark output separation:

```bash
ARG="4 67 3 87 23"
./push_swap --bench $ARG > out.txt 2> err.txt
cat out.txt
cat err.txt
```

## Resources

- 42 Push_swap subject
- 42 Norm
- `man malloc`
- `man free`
- `man write`
- Big-O notation references
- Stack data structure references
- Binary radix sort references
- Chunk-based sorting explanations
- YouTube tutorial: *Push swap tuto [less than 4000 operations]* by `@addr_0x2a`
- Peer review and manual testing

## Use of AI

AI was used as a support tool during the project.

It helped with documentation, edge-case review, complexity clarification, Norm-related refactoring ideas, and README structuring.

All implementation choices were reviewed, adapted and tested by the contributors.

## Contributors

The project was developed collaboratively. Both contributors worked on understanding the Push_swap operation model, testing the program, reviewing edge cases, and preparing the project for evaluation.

### tsalland

Main contributions:

- initial project structure and first working implementation;
- implementation of the core stack operations;
- main work on the simple sorting strategy;
- main work on the medium sorting strategy and chunk-based approach;
- initial Makefile setup and compilation workflow;
- debugging of the sorting behavior;
- performance-oriented work on operation counts;
- general algorithmic design and project integration.

### csodini

Main contributions:

- review of the subject requirements and project compliance;
- implementation of the complex sorting strategy in `complex.c`;
- index initialization and assignment work for the complex strategy;
- correction of `ft_adaptive`, including strategy selection and disorder type handling;
- refactoring for Norm compatibility, including operation files, long functions, `main`, and `t_context`;
- parser and error-handling improvements, including no-argument behavior, optional signs, and overflow guard;
- memory-management improvements, including `ft_free_stack` and safer allocation failure handling;
- benchmark output cleanup, Makefile/header cleanup, README writing, and final documentation.

## Final note

This project follows the 42 Norm and can be tested through compilation, manual tests, benchmark mode, and checker validation.
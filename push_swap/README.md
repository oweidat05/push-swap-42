*This activity has been created as part of the 42 curriculum by mowaidat , qalrawab.*

# push_swap

## Description

push_swap is a sorting program written in C that sorts a list of
integers using two stacks (A and B) and a limited set of allowed
operations.

The objective is to generate the smallest possible sequence of
instructions that sorts the stack in ascending order.

This project focuses on:

• Algorithmic complexity analysis\
• Data structures (linked lists, stacks)\
• Adaptive algorithm selection\
• Optimization of instruction count\
• Memory management and error handling

Unlike traditional sorting, push_swap does not directly rearrange
values. Instead, it generates a sequence of operations that transforms
the stack into a sorted state.

------------------------------------------------------------------------

## Allowed Operations

The following operations are used:

swap: sa → swap first two elements of stack A\
sb → swap first two elements of stack B\
ss → sa and sb at the same time

push: pa → push top element from B to A\
pb → push top element from A to B

rotate: ra → rotate A (first element becomes last)\
rb → rotate B\
rr → ra and rb

reverse rotate: rra → reverse rotate A\
rrb → reverse rotate B\
rrr → rra and rrb

------------------------------------------------------------------------

## Project Architecture

The project is modular and organized for clarity, maintainability, and
Norminette compliance.

    push_swap/
    │
    ├── includes/
    │   └── push_swap.h
    │
    ├── libft/
    │   └── custom standard library functions
    │
    ├── src/
    │   ├── main/
    │   │   ├── push_swap.c
    │   │   ├── parse_options.c
    │   │   └── benchmark.c
    │   │
    │   ├── argument/
    │   │   ├── process_argument.c
    │   │   ├── string_argument.c
    │   │   └── stack_linked.c
    │   │
    │   ├── operation/
    │   │   ├── swap_a_b.c
    │   │   ├── push_a_b.c
    │   │   ├── rotate_a_b.c
    │   │   └── rotrotate_a_b.c
    │   │
    │   └── algorithm/
    │       ├── simple/
    │       │   ├── sort_three.c
    │       │   ├── sort_four.c
    │       │   ├── sort_five.c
    │       │   └── simple_big_5number.c
    │       │
    │       ├── medium/
    │       │   ├── sort_medium.c
    │       │   └── medium_utils.c
    │       │
    │       ├── complex/
    │       │   └── complex_sort.c
    │       │
    │       └── disorder.c
    │
    └── Makefile

------------------------------------------------------------------------

## Core Design

The program uses an adaptive strategy that selects the most efficient
algorithm based on:

• input size\
• disorder level\
• instruction cost

Main controller:

push_swap.c

Responsibilities:

• parse input\
• create stacks\
• select strategy\
• execute sorting\
• track operations\
• free memory

------------------------------------------------------------------------

## Algorithms Used

This project implements three sorting strategies.

------------------------------------------------------------------------

### Simple Strategy --- Bubble Sort Adaptation

File: simple_big_5number.c

Used for small inputs.

Concept:

Compare adjacent elements and swap them using stack operations.

Complexity:

Time: O(n²)\
Space: O(1)

Reason for use:

Small input size → minimal overhead → optimal performance.

------------------------------------------------------------------------

### Medium Strategy --- Chunk-based Sorting

Files: sort_medium.c\
medium_utils.c

Concept:

Split sorted index range into chunks:

Example:

indexes: 0 1 2 3 4 5 6 7 8 9

chunk size = 3

chunks:

0--2\
3--5\
6--8\
9

Process:

• push chunk elements to stack B\
• maintain partial order\
• push back to stack A in correct order

Complexity:

Time: O(n√n)

Reason:

Reduces unnecessary rotations compared to naive algorithms.

------------------------------------------------------------------------

### Complex Strategy --- Radix Sort Adaptation

File: complex_sort.c

Concept:

Sort based on binary representation of indexes.

Example:

index: 5 → binary: 101

Process:

check bit 0\
check bit 1\
check bit 2

Use push and rotate operations.

Complexity:

Time: O(n log n)

Reason:

Most efficient for large input sizes.

Used for 500+ numbers.

------------------------------------------------------------------------

## Adaptive Strategy

File: push_swap.c

Automatically selects best algorithm:

if size ≤ 5 → simple\
if medium disorder → chunk\
if large size → radix

This ensures optimal performance across all inputs.

------------------------------------------------------------------------

## Benchmark System

File: benchmark.c

Tracks:

• total operations\
• operation types\
• disorder level\
• strategy used

Example:

\[bench\] total_ops: 6072

Benchmark output is printed to stderr to avoid interfering with checker.

------------------------------------------------------------------------

## Compilation

make

------------------------------------------------------------------------

## Usage

Basic:

./push_swap 3 2 1

With benchmark:

./push_swap --bench 3 2 1

With strategy selection:

./push_swap --simple 3 2 1\
./push_swap --medium 3 2 1\
./push_swap --complex 3 2 1

------------------------------------------------------------------------

## Error Handling

Handles:

• invalid input\
• duplicates\
• overflow\
• memory allocation failure

------------------------------------------------------------------------

## Performance

Achieved results:

100 numbers:

\< 700 operations

500 numbers:

\~6000 operations

Meets 42 project requirements.

------------------------------------------------------------------------

## Resources

42 subject: push_swap subject PDF

Documentation:

man malloc\
man free\
man read

Algorithm references:

Radix Sort\
Bubble Sort\
Stack data structures

42 Norminette standard

------------------------------------------------------------------------

## Contributors

Login: mowaidat\
qalrawab

Work Distribution:

Mohammad Ali Oweidat:

• project architecture\
• simple algorithms\
• main controller\
• argument parsing\
• memory management\
• operations implementation

Qusai Alrawabdah:

• medium algorithm\
• radix algorithm\
• disorder calculation\
• benchmark system

Shared work:

• testing\
• debugging\
• optimization

------------------------------------------------------------------------

## Authors

Author: Mohammad Ali Oweidat\
Qusai Alrawabdah

------------------------------------------------------------------------

## Notes

This project strictly follows:

• 42 coding standards\
• Norminette\
• memory safety rules\
• modular architecture

The implementation focuses on both correctness and performance
optimization.

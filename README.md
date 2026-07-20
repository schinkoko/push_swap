*This project has been created as part of the 42 curriculum by aschinog, mtrukhin.*

<div align="center">

# push_swap

### Sorting integers with two stacks, eleven operations, and as few moves as possible

![C](https://img.shields.io/badge/language-C-00599C?style=flat-square)
![42](https://img.shields.io/badge/school-42-000000?style=flat-square)
![Algorithms](https://img.shields.io/badge/focus-algorithms-6C63FF?style=flat-square)

</div>

> `push_swap` analyzes an integer sequence and prints a valid sequence of stack operations that sorts it in ascending order. This implementation contains three explicit sorting strategies, an adaptive dispatcher based on input disorder, benchmark reporting, and a checker program.

## Contents

- [Description](#description)
- [Instructions](#instructions)
- [Operations](#operations)
- [Algorithm design](#algorithm-design)
- [Benchmark mode](#benchmark-mode)
- [Checker](#checker)
- [Project structure](#project-structure)
- [Contributions](#contributions)
- [Resources and AI usage](#resources-and-ai-usage)

## Description

The program starts with two linked-list stacks:

- **Stack A** contains unique signed integers; its first value is the top.
- **Stack B** starts empty.

The goal is to leave **A sorted from smallest to largest** and **B empty**, using only the operations defined by the project. Instead of sorting the original values directly, the program assigns every value a normalized rank from `0` to `n - 1`. Ranking preserves order while making chunk boundaries and binary radix passes straightforward.

### Main features

- Parses separate arguments and quoted, space-separated lists.
- Rejects non-numeric input, duplicates, and values outside the `int` range.
- Supports forced `simple`, `medium`, `complex`, and `adaptive` strategies.
- Computes an inversion-based disorder score before making any move.
- Reports total and per-operation statistics through `--bench` on `stderr`.
- Includes a bonus `checker` executable.

## Instructions

### Compilation

```bash
make            # build push_swap
make bonus      # build checker
make clean      # remove object files
make fclean     # remove objects and executables
make re         # rebuild push_swap from scratch
```

The project is compiled with:

```text
-Wall -Wextra -Werror
```

### General syntax

```bash
./push_swap [--simple | --medium | --complex | --adaptive] [--bench] <integers...>
```

`--adaptive` is the default when no strategy selector is supplied. Only one strategy selector may be used, while `--bench` can be combined with any strategy.

### Examples

```bash
./push_swap 2 1 3 6 5 8
./push_swap --medium "8 3 6 1 5 2 7 4"
./push_swap --complex 4 67 3 87 23
```

Store arguments once and validate the generated operation stream:

```bash
ARG="4 67 3 87 23"
./push_swap --adaptive $ARG | ./checker $ARG
```

Count generated operations:

```bash
ARG="$(shuf -i 0-999999 -n 100 | tr '\n' ' ')"
./push_swap --adaptive $ARG | wc -l
```

### Error handling

Invalid input prints `Error` followed by a newline to `stderr`.

```bash
./push_swap 1 two 3       # non-integer
./push_swap 3 2 3         # duplicate
./push_swap 2147483648    # outside INT_MAX
```

With no integer arguments, the program exits without printing operations.

## Operations

| Operation | Effect |
|:--|:--|
| `sa` / `sb` | Swap the first two values of A / B |
| `ss` | Perform `sa` and `sb` together |
| `pa` | Push the top of B onto A |
| `pb` | Push the top of A onto B |
| `ra` / `rb` | Rotate A / B upward; the first value becomes the last |
| `rr` | Perform `ra` and `rb` together |
| `rra` / `rrb` | Reverse-rotate A / B; the last value becomes the first |
| `rrr` | Perform `rra` and `rrb` together |

## Algorithm design

The project measures complexity by the **number of emitted push_swap operations**, not only by the C runtime of linked-list traversal.

### 1. Rank normalization

For each node, the program counts how many values are smaller and stores that count as its `index`:

```text
Values:  42  -5  17  100  3
Ranks:    3   0   2    4  1
```

The ranks are unique, non-negative, and limited to `0 ... n - 1`. All sorting strategies work with these ranks.

### 2. Simple strategy - selection extraction

**Selector:** `--simple`  
**Target operation class:** `O(n²)`

The algorithm repeatedly:

1. Finds the smallest rank remaining in A.
2. Chooses `ra` or `rra` according to the target's shortest distance to the top.
3. Pushes the minimum to B with `pb`.
4. Pushes every value back to A with `pa` after A becomes empty.

Each extraction can require a linear number of rotations, repeated for `n` values, which gives the quadratic upper bound. It is simple and predictable, making it useful as a baseline and for low-disorder inputs selected by the adaptive mode.

### 3. Medium strategy - square-root chunk sort

**Selector:** `--medium`  
**Target operation class:** `O(n√n)`

The rank interval is divided into chunks whose width is approximately `√n`:

```text
0 ... chunk_size - 1
chunk_size ... 2 * chunk_size - 1
...
```

For each chunk, the algorithm:

1. Searches A for a rank inside the active range.
2. Checks whether an eligible node is in the upper half of A.
3. Uses `ra` or `rra` to approach the chunk from the shorter direction.
4. Pushes eligible nodes to B.
5. Uses the chunk midpoint to influence B's layout.

After all chunks have been transferred, the largest remaining rank in B is repeatedly moved to the top using `rb` or `rrb`, then returned to A with `pa`. Pulling maxima in descending order rebuilds A in ascending order.

This strategy accepts any value within the current range instead of searching for one exact value, reducing long rotations on medium-sized or moderately disordered inputs. The ordering of B is the key factor to monitor when validating the intended `O(n√n)` operation target.

### 4. Complex strategy - binary LSD radix sort

**Selector:** `--complex`  
**Operation class:** `O(n log n)`

The normalized ranks are processed bit by bit, starting with the least-significant bit:

```text
bit = 0, 1, 2, ...
```

For every bit position:

- A rank with bit `0` is pushed to B using `pb`.
- A rank with bit `1` is kept in A and rotated using `ra`.
- When the pass is complete, every node in B is returned with `pa`.

There are `ceil(log₂ n)` bit positions, and each pass performs a linear number of operations, producing an `O(n log n)` operation bound. Radix sort is stable across each bit pass and is the most reliable strategy for large or highly disordered inputs.

### 5. Adaptive strategy and disorder

**Selector:** `--adaptive` or no selector

Disorder is calculated before sorting as the normalized inversion count:

```text
disorder = inversions / total_pairs
total_pairs = n * (n - 1) / 2
```

An inversion is a pair where a larger value appears before a smaller value. Therefore:

- `0.00` means already ordered.
- Values near `0.50` indicate mixed order.
- `1.00` means reverse order.

| Disorder range | Internal strategy | Intended class | Rationale |
|:--|:--|:--|:--|
| `< 0.20` | Selection extraction | `O(n²)` | Low disorder favors a straightforward baseline with limited movement in typical cases |
| `0.20 ... < 0.50` | Chunk sort | `O(n√n)` | Range-based extraction balances scan cost and organization of B |
| `>= 0.50` | Binary radix sort | `O(n log n)` | High disorder benefits from input-independent bitwise passes |

The sorting phase uses `O(1)` auxiliary bookkeeping beyond the linked-list nodes. Including both stacks and parsed input, total program storage is `O(n)`.

## Benchmark mode

`--bench` keeps the operation stream on `stdout` and writes metrics to `stderr`:

```bash
ARG="4 67 3 87 23"
./push_swap --bench --adaptive $ARG > operations.txt 2> benchmark.txt
cat benchmark.txt
```

Reported fields:

- Disorder percentage with two decimal places.
- Selected strategy and declared complexity class.
- Total operation count.
- Individual counts for `sa`, `sb`, `ss`, `pa`, `pb`, `ra`, `rb`, `rr`, `rra`, `rrb`, and `rrr`.

### Subject performance targets

| Input size | Pass | Good | Excellent |
|--:|--:|--:|--:|
| 100 random integers | `< 2000` | `< 1500` | `< 700` |
| 500 random integers | `< 12000` | `< 8000` | `< 5500` |

Use repeated randomized tests rather than relying on a single favorable input.

## Checker

Build the bonus executable with:

```bash
make bonus
```

The checker receives the same initial values, reads one operation per line from standard input, executes the supported instructions, and verifies the final state:

- `OK` when A is sorted and B is empty.
- `KO` otherwise.

```bash
ARG="3 2 1 0"
printf "rra\npb\nsa\nrra\npa\n" | ./checker $ARG
```

## Project structure

| Area | Files | Responsibility |
|:--|:--|:--|
| Entry points | `push_swap.c`, `checker.c` | Main sorter and verification program |
| Configuration | `push_swap.h`, `Makefile` | Types, constants, prototypes, build rules |
| Parsing | `parse_args.c`, `parse_utils.c`, `ft_split.c` | Flags, integers, ranges, duplicates, argument splitting |
| Data structures | `ft_lstops.c`, `other_utils.c` | Linked-list management, rank assignment, benchmark state |
| Operations | `ops_ps.c`, `ops_rot.c`, `ops_cmb.c` | Push, swap, rotate, reverse-rotate, combined operations |
| Strategies | `set_strategy.c`, `sort_algos.c` | Disorder measurement, adaptive selection, three algorithms |
| Sorting helpers | `sort_utils.c`, `chunk_utils.c` | Position lookup, shortest rotations, chunk transfer and recovery |
| Local utilities | `ft_printf.c`, `print_utils.c`, `get_next_line.c`, `get_next_line_utils.c` | Output formatting and checker input |

## Contributions

The implementation was completed collaboratively, with both learners responsible for understanding and defending the complete project.

| Learner | Main contributions |
|:--|:--|
| **aschinog** | Program entry point, shared header and data model, Makefile, linked-list operations, stack instructions, core sorting algorithms, position/min-max helpers, integration and review |
| **mtrukhin** | Argument parsing and validation, strategy selection and disorder metric, chunk helpers, benchmark reporting, checker foundation, local `printf`, `split`, and line-reading utilities |
| **Both** | Algorithm discussion, debugging, testing, Norm compliance, performance analysis, and final integration |

## Resources and AI usage

### References

- Push Swap subject
- [Big-O notation](https://en.wikipedia.org/wiki/Big_O_notation)
- [Selection sort](https://en.wikipedia.org/wiki/Selection_sort)
- [Radix sort](https://en.wikipedia.org/wiki/Radix_sort)
- [42 Norm](https://github.com/42School/norminette)

### AI usage

AI was used to help create this README, summarize the project requirements, and turn the implemented sorting logic into concise explanations. It was also used as a documentation aid for clarifying chunk sorting, radix passes, disorder thresholds, test commands, and complexity terminology.
# Push Swap: Efficient Stack Sorting Algorithm

## 📋 Table of Contents

- [About](#about)
- [Project Overview](#project-overview)
- [Rules & Operations](#rules--operations)
- [Installation & Usage](#installation--usage)
- [Algorithm Strategy](#algorithm-strategy)
- [Performance Benchmarks](#performance-benchmarks)
- [Error Handling](#error-handling)
- [Testing](#testing)
- [Makefile Targets](#makefile-targets)

## About

**Push Swap** is a sorting algorithm project that efficiently sorts integers using two stacks (a and b) with a limited set of operations. The challenge is to find the shortest sequence of operations to sort the stack in ascending order.

## Project Overview

The program takes a list of integers as input and outputs the optimal sequence of operations to sort them using two stacks:

- **Stack a**: Contains the initial random integers to be sorted
- **Stack b**: Empty stack used as temporary storage

### Rules & Operations

The available operations are:

| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack a |
| `sb` | Swap first two elements of stack b |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push top element from b to a |
| `pb` | Push top element from a to b |
| `ra` | Rotate stack a up (first becomes last) |
| `rb` | Rotate stack b up (first becomes last) |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack a (last becomes first) |
| `rrb` | Reverse rotate stack b (last becomes first) |
| `rrr` | `rra` and `rrb` simultaneously |

## Installation & Usage

### Compilation

```bash
git clone https://github.com/viridian-green/Push_Swap.git
cd push_swap
make
```

### Basic Usage

```bash
# Sort a list of integers
./push_swap 4 67 3 87 23

# Using environment variable
ARG="4 67 3 87 23"; ./push_swap $ARG

# Count number of operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l
```

### Validation with Checker

```bash
# Check if operations correctly sort the stack
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_OS $ARG
# Should output "OK" if correct, "KO" if incorrect
```

## Algorithm Strategy

### For Small Stacks (≤5 elements)
- **Direct sorting** with minimal operations
- **Optimized sequences** for each possible configuration
- **Manual comparison** and swapping

### For Medium/Large Stacks (≥100 elements)
- **Chunk-based sorting** algorithm
- **Divide and conquer** approach
- **Pivot selection** for efficient partitioning
- **Smart rotation** strategies

### Key Optimization Techniques
- **Cost calculation** for each potential move
- **Operation combination** (e.g., using `rr` instead of `ra` + `rb`)
- **Reverse rotation** optimization
- **Minimal operation** pathfinding

## Performance Benchmarks

The algorithm meets the following performance requirements:

| Stack Size | Target Operations | Achieved |
|------------|-------------------|----------|
| 3 elements | ≤ 3 operations | ✅ |
| 5 elements | ≤ 12 operations | ✅ |
| 100 elements | < 700 operations | ✅ |
| 500 elements | < 5500 operations | ✅ |

### Validation Levels
- **100% validation**: 100 numbers in <700 ops, 500 numbers in <5500 ops
- **Minimum validation**: 100 numbers in <1100 ops, 500 numbers in <8500 ops

## Error Handling

The program handles various error cases:

```bash
# Invalid arguments
./push_swap 1 2 "three" 4      # Output: Error
./push_swap 1 2 3 3 4          # Output: Error (duplicates)
./push_swap 1 2 9999999999999  # Output: Error (integer overflow)

# No arguments
./push_swap                    # No output, returns to prompt
```


## Makefile Targets

```bash
make           # Compile push_swap executable
make clean     # Remove object files
make fclean    # Remove object files and executable
make re        # Clean and recompile
make bonus     # Compile bonus part (checker program)
```



## Dependencies

- **libft**: Custom C library (included)
- **Standard C Library**: malloc, free, write, exit
- **Checker program**: Provided separately for validation


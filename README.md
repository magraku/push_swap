*This activity has been created as part of the 42 curriculum by axweinma, gerramir.*

# Push_swap

## Description

Push_swap is a sorting algorithm project where two stacks (a and b) and a limited set of operations are used to sort a list of integers with the fewest possible moves. The goal is to implement and compare four distinct sorting strategies of increasing complexity, and to select the best one automatically based on how disordered the input is.

## Instructions

### Compilation
```bash
make        # compile
make clean  # remove object files
make fclean # remove object files and binary
make re     # recompile from scratch
```

### Usage
```bash
./push_swap [strategy] [--bench] <list of integers>
```

### Strategy flags (optional)
| Flag | Strategy | Complexity |
|------|----------|------------|
| `--simple` | Selection sort | O(n²) |
| `--medium` | Chunk-based sort | O(n√n) |
| `--complex` | Radix sort (LSD) | O(n log n) |
| `--adaptive` | Auto-select by disorder | depends |

If no strategy flag is given, `--adaptive` is used by default.

### Benchmark flag (optional)
`--bench` can be combined with any strategy flag. It prints sorting metrics to stderr after sorting:
```bash
./push_swap --bench 9 3 7 1 5
./push_swap --bench --simple 9 3 7 1 5
./push_swap --bench --complex 9 3 7 1 5
```

Output example:
```
[bench] disorder:  49.93%
[bench] strategy:  Adaptive / O(n√n)
[bench] total_ops:  7997
[bench] sa:  0  sb:  0  ss:  0  pa:  500  pb:  500
[bench] ra:  4840  rb:  1098  rr:  0  rra:  0  rrb:  1059  rrr:  0
```

### Examples
```bash
# Sort numbers
./push_swap 3 1 4 5 9 2 6

# Force simple strategy
./push_swap --simple 5 4 3 2 1

# Force complex strategy and verify with checker
ARG="4 67 3 87 23"
./push_swap --complex $ARG | ./checker_linux $ARG

# Test with 100 random numbers
ARG=$(shuf -i 0-9999 -n 100 | tr '\n' ' ')
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker_linux $ARG

# Test with 500 random numbers and save bench
shuf -i 0-9999 -n 500 > args.txt
./push_swap --bench $(cat args.txt) 2> bench.txt | ./checker_linux $(cat args.txt)
cat bench.txt
```

### Error cases
```bash
./push_swap 3 2 one 1     # Error — non-integer argument
./push_swap 3 2 3 1       # Error — duplicate values
./push_swap 3 99999999999 # Error — integer out of range
```

## How it works

### Available operations
| Operation | Description |
|-----------|-------------|
| `sa` | Swap first two elements of stack a |
| `sb` | Swap first two elements of stack b |
| `ss` | sa and sb at the same time |
| `pa` | Push top of b to top of a |
| `pb` | Push top of a to top of b |
| `ra` | Rotate a upward (first becomes last) |
| `rb` | Rotate b upward (first becomes last) |
| `rr` | ra and rb at the same time |
| `rra` | Reverse rotate a (last becomes first) |
| `rrb` | Reverse rotate b (last becomes first) |
| `rrr` | rra and rrb at the same time |

### Disorder metric
Before any moves, the program computes the disorder of stack a — a value between 0.0 and 1.0:
- **0.0** — already sorted
- **1.0** — completely reversed

It counts all pairs (i, j) where i appears before j in the stack but i > j (inversions), divided by the total number of pairs.

## Strategies

### Simple — O(n²)
Selection sort adaptation. At each step, finds the minimum element in stack a by its position, rotates it to the top using `ra` or `rra` (whichever is shorter), then pushes it to b with `pb`. Once all elements are in b, pushes them all back to a with `pa`. Used by adaptive when **disorder < 0.2**.

### Medium — O(n√n)
Chunk-based sorting using ranks:
1. Assigns a rank to every element (0 = smallest, n-1 = largest)
2. Divides ranks into √n chunks (e.g. 10 chunks of 10 for 100 elements)
3. For each chunk, scans stack a and pushes matching elements to b with `pb`, rotating others with `ra`
4. Pulls elements back from b to a in descending order using `rb`/`rrb` to find the maximum, then `pa`

Used by adaptive when **0.2 ≤ disorder < 0.5**.

### Complex — O(n log n)
Radix sort (LSD) adaptation using binary representation of ranks:
1. Assigns a rank to every element
2. For each bit (from least significant to most significant):
   - Elements whose current bit is 0 are pushed to b with `pb`
   - Elements whose current bit is 1 stay in a via `ra`
   - All elements in b are pushed back to a with `pa`
3. After log₂(n) passes, stack a is sorted

Used by adaptive when **disorder ≥ 0.5**.

### Adaptive
Measures disorder before sorting and selects the optimal strategy:
- disorder < 0.2 → Simple O(n²) — nearly sorted, few moves needed
- 0.2 ≤ disorder < 0.5 → Medium O(n√n) — moderate disorder
- disorder ≥ 0.5 → Complex O(n log n) — high disorder, need powerful algorithm

## Performance targets
|  Input size |   Minimum   |     Good   | Excellent  |
|-------------|-------------|------------|------------|
| 100 numbers | < 2000 ops  | < 1500 ops | < 700 ops  |
| 500 numbers | < 12000 ops | < 8000 ops | < 5500 ops |

## Resources
- [Sorting algorithms — Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
- [Radix sort — Wikipedia](https://en.wikipedia.org/wiki/Radix_sort)
- [Big-O notation — Wikipedia](https://en.wikipedia.org/wiki/Big_O_notation)
- [Push_swap visualizer](https://github.com/o-reo/push_swap_visualizer)

### AI Usage
Claude (Anthropic) was used throughout this project to:
- Guide the implementation of sorting algorithms (chunk sort, radix sort, adaptive strategy)
- Debug parsing, movement functions, and memory management
- Help structure the disorder metric and threshold selection
- Review edge cases and norm compliance

All AI-generated suggestions were reviewed, tested, and adapted by both learners before integration.

## Contributors
- **axweinma** — Algorithm design (complex/adaptive), movements, parsing
- **gerramir** — Algorithm design (simple/medium), benchmark mode, Makefile, project structure
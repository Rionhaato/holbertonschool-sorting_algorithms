# Sorting Algorithms

Practice implementations of classic sorting algorithms in C. This project uses the Holberton/ALX `sort.h` interface with helper printers for arrays and doubly linked lists.

## Files
- `0-bubble_sort.c` — bubble sort for integer arrays, prints after each swap.
- `0-O` — Big O time complexities for bubble sort (best/average/worst).
- `1-insertion_sort_list.c` — insertion sort for doubly linked lists, prints after each swap.
- `1-O` — Big O time complexities for insertion sort (best/average/worst).
- `print_array.c` — helper to print arrays.
- `print_list.c` — helper to print doubly linked lists.
- `sort.h` — shared types and prototypes.
- `0-main.c`, `1-main.c` — local test harnesses (not checked by project tests).

## Build and run (local)
```sh
gcc -Wall -Wextra -Werror -pedantic 0-bubble_sort.c 0-main.c print_array.c -o bubble
./bubble

gcc -Wall -Wextra -Werror -pedantic 1-insertion_sort_list.c 1-main.c print_list.c -o insertion
./insertion
```

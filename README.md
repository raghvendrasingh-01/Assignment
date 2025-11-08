# Assignment
Assignment in C

## Assignment 1: Name Without Semicolon

### Program: `nameWithoutSemicolon.c`

**Objective:** Write a C program that prints your name without using a semicolon after the `printf` statement.

### How It Works:

The program demonstrates a creative approach to avoid using a semicolon after `printf` by utilizing the following concepts:

1. **Return Value of `printf`:** The `printf` function returns an integer value representing the number of characters successfully printed to the output stream.

2. **Conditional Statement:** The program uses an `if` statement to evaluate the return value of `printf`. Since `printf("Raghvendra Singh\n")` prints 17 characters (including the newline), it returns 17, which is a non-zero (true) value.

3. **Empty Block:** The `if` statement has an empty block `{}`, so no additional action is performed, but the semicolon requirement is satisfied by the `if` statement structure rather than directly after `printf`.

### Code Explanation:
```c
if (printf("Raghvendra Singh\n")) {}
```
- `printf("Raghvendra Singh\n")` executes and prints the name
- Returns the number of characters printed (17)
- The `if` condition evaluates to true (non-zero)
- Empty block executes (does nothing)
- The semicolon belongs to the `if` statement, not directly to `printf`

### Output:
```
Raghvendra Singh
```

This clever solution demonstrates understanding of:
- Function return values
- Conditional statements
- C syntax flexibility

---

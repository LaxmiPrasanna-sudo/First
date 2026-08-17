# README.md

## 1. Title

**FIRST Function Calculation for a Given Grammar**

## 2. Objective

To develop a C program to calculate the **FIRST** set of non-terminals for a given context-free grammar.

## 3. Problem Statement

Write a C program to calculate the FIRST function for the grammar:

```text
E → E + T
E → T
T → T * F
T → F
F → (E)
F → id
```

## 4. Algorithm

1. Start the program.
2. Define the given grammar.
3. For each non-terminal, find its productions.
4. If a production starts with a terminal, add it to FIRST.
5. If it starts with a non-terminal, find the FIRST of that non-terminal.
6. Repeat until no new symbols can be added.
7. Display the FIRST set of each non-terminal.
8. Stop.

## 5. Source Code

**File:** `first.c`

The C program accepts the grammar and calculates the FIRST sets of `E`, `T`, and `F`.

## 6. Sample Input

```text
E->E+T
E->T
T->T*F
T->F
F->(E)
F->id
```

## 7. Sample Output

```text
FIRST(E) = { (, id }
FIRST(T) = { (, id }
FIRST(F) = { (, id }
```

## 8. Grammar Classification

| Symbol | Type         |
| ------ | ------------ |
| `E`    | Non-Terminal |
| `T`    | Non-Terminal |
| `F`    | Non-Terminal |
| `+`    | Terminal     |
| `*`    | Terminal     |
| `(`    | Terminal     |
| `)`    | Terminal     |
| `id`   | Terminal     |

## 9. Test Cases

### Test Case 1

```text
E -> E + T
```

Expected FIRST symbols are obtained through `E -> T -> F`.

### Test Case 2

```text
F -> (E)
```

`FIRST(F)` contains `(`.

### Test Case 3

```text
F -> id
```

`FIRST(F)` contains `id`.

## 10. Conclusion

The C program successfully calculates the FIRST sets for the given grammar. The result is:

```text
FIRST(E) = { (, id }
FIRST(T) = { (, id }
FIRST(F) = { (, id }
```

This demonstrates the basic concept of finding FIRST sets used in **syntax analysis and compiler design**.
# First

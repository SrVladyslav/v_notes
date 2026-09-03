## Diagonal Index Formulas

For a matrix cell `(i, j)`:

### Quick rule

```text
Row        -> i
Column     -> j
Diagonal \ -> i - j + cols - 1
Diagonal / -> i + j
```

### Descending diagonal `\`

Cells on the same `\` diagonal keep:

```text
i - j = constant
```

Because moving diagonally means:

```text
(i, j) -> (i + 1, j + 1)
```

and:

```text
(i + 1) - (j + 1) = i - j
```

Since `i - j` can be negative, shift it:

```cpp
index = i - j + cols - 1;
```

### Ascending diagonal `/`

Cells on the same `/` diagonal keep:

```text
i + j = constant
```

Because moving diagonally means:

```text
(i, j) -> (i + 1, j - 1)
```

and:

```text
(i + 1) + (j - 1) = i + j
```

So the index is simply:

```cpp
index = i + j;
```

The goal is to give every cell on the same diagonal the same index, so their values can be accumulated in one array position.

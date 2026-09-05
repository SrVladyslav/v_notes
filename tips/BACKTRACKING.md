# Backtracking

> ![IMPORTTANT]
> `4^n / sqrt(n)` is Catalan number, and this is the number of possible combinations, so if you are going to write a combination for pair of symbols, you should know that this is the combination for every possible pair. Therefore, the time complexity is `O(n*4^n / sqrt(n))` and the memory complexity is `O(n*4^n / sqrt(n))`.

```text
Remember, that in backtracking you should check for the State with the value and some counters, so they can help you to know the current state and if is changed.
```

## Mathematical approach

The cataln numer is deduced from the fact that the number of ways to choose `n` elements from `n` elements is `C(n,n) = n!`.

This is the same as the number of ways to choose `n` elements from `n+1` elements, which is `C(n+1,n) = C(n,n) + C(n,n-1) = n! + n! = 2n!`.

So the number of ways to choose `n` elements from `n+1` elements is `2n!`.

## Example:

Given number n, you need to generate all the possible combinations of same pair symbols ().
It should have the opening and closing symbols in the same pair.
The idea of the optimal solution is to generate all the good combinations from start.

Example:
n = 3
result ["((()))", "(()())", "(())()", "()()()"]

### In this case, use a queue

```cpp
struct State
{
    string prefix;
    int open_used;
    int close_used;
};
```

Then the next approach is the same as in the original one, but since we want all the combinations, we should create a new extra quque, `running_queue`,
so we add there the initial state `State{{"",0,0}}` and then just run the while while the running queue hase something in it or the first element of that queue is not longer than the original list to combine.

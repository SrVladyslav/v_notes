# Bruteforce combinations

In cases we are asked to perform all the combinations of a numbers or elements fromn a list, where the order doesn't matter but the repetitions are not allowed, we should do the bruteforce approach by running an extra queue list,
but since this will lead a full permutations, we should rely on an external state which will have the current value and the next allowed index of combinations from the original list.

## Example:

Given a list of a unique numbers nums. We should find all the possiblec ombinations between them, including the basic list and the nums. The order inside the combinations doesn't matter. Same combinations should not repeat.

e.g.
nums = [3,6,17]
output = [[], [3], [6], [3,6], [17], [3,17], [6,17], [3,6,17]]

### In this case, use an extra state

```cpp

struct State
{
    vector<int> prefix;
    int next_index; // To not repeat the same combination, we are only allowed to use the next values
};
```

Then the next approach is the same as in the original one, but since we want all the combinations, we should create a new extra quque, `running_queue`,
so we add there the initial state `State{{{},0}}` and then just run the while while the running queue hase something in it or the first element of that queue is not longer than the original list to combine.

Inside the while we will be adding all the elements from the original list from the next_index towards the end to the front prefix of the current running queue. and this should be added to the running queue with the next state incremented in one.

Add the result to the result to the result list too.

/**
 * Given a list of unique numbers nums. We should return all the possible
 * combinations of the eneemts from the list. Every combination should use
 * all the elements from the list once. The order inside the combinations
 * doesn't matter. Same combinations should not repeat.
 *
 * e.g.
 * nums = [1,2,3]
 * output = [[1,2,3], [1,3,2], [2,1,3], [2,3,1], [3,1,2], [3,2,1]]
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

struct State
{
    vector<int> current;
    vector<bool> used;
};

vector<vector<int>> generate_numeric_combinations(vector<int> &nums)
{
    vector<vector<int>> result;
    stack<State> states;

    states.push({{},
                 vector<bool>(nums.size(), false)});

    while (!states.empty())
    {
        // Obtain the last state processed from the stack
        State state = states.top();
        states.pop();

        // If we have the full mermutation, we shoudl add it to the result
        // Since it has the samelength as the nums vector. Base case basically
        if (state.current.size() == nums.size())
        {
            result.push_back(state.current);
            continue;
        }

        // Now add all the remaining possible permutations to the stack
        // NOTE: STACK IS LIFO, so we should iterate from the end to the start
        for (int i = nums.size() - 1; i >= 0; i--)
        {
            // Check if the state is already used or not
            if (state.used[i])
                continue;

            // If is not used, we should add the new permutation to the stack and mark the value used
            State new_state = state;
            new_state.current.push_back(nums[i]);
            new_state.used[i] = true;

            states.push(new_state);
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {1, 2, 3};

    printf("Combinations for [1,2,3]\n");

    vector<vector<int>> res = generate_numeric_combinations(nums);

    for (auto &item : res)
    {
        for (auto &item2 : item)
            cout << item2 << " ";
        cout << "\n";
    }

    return 0;
}
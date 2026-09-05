/**
 * Given a list of a unique numbers nums. We should find all the possible combinations between them,
 * including the basic list and the nums. The order inside the combinations doesn't matter.
 * Same combinations should not repeat.
 *
 * e.g.
 * nums = [3,6,17]
 *
 * output = [[], [3], [6], [3,6], [17], [3,17], [6,17], [3,6,17]]
 *
 * Time: O(n*2^n)
 * Memory: O(n*2^n)
 */

#include <iostream>
// #include <algorithm>
#include <vector>
#include <unordered_map>

using namespace std;

struct State
{
    vector<int> prefix;
    int next_index; // To not repeat the same combination, we are only allowed to use the next values
};

vector<vector<int>> generate_numeric_combinations(vector<int> nums)
{
    // Instead of deleting numbs from the list while processing,
    // we already will have the those as initial result combinations
    vector<vector<int>> result{{}};

    // Now we will create the running result with the current state
    vector<State> running_result{{{}, 0}}; // This means that it can use all the values from 0 on for combinations

    while (!running_result.empty() && running_result.front().prefix.size() < nums.size())
    {
        // We obtain the last state of the running result
        State current_state = running_result.front();
        // Delete the front value, since we should pop it
        running_result.erase(running_result.begin());

        // Now we should create all the combinations with the current state
        for (int i = current_state.next_index; i < nums.size(); i++)
        {
            // Creating a new prefix combination
            vector<int> new_prefix = current_state.prefix;
            // We add the next number to the prefix to create the new combination
            new_prefix.push_back(nums[i]);

            // Now we publish the new combination to the list to proceed with the combinations
            State new_state = {new_prefix,
                               i + 1}; // Since we start from i, we should note that the next should start from the next value
            running_result.push_back(new_state);

            // Finally, add the combination to the result array
            result.push_back(new_prefix);
        }
    }

    return result;
}

int main()
{
    vector<int> nums = {3, 6, 17};

    cout << "Combinations for: 3 6 17:" << endl;

    vector<vector<int>> res = generate_numeric_combinations(nums);
    for (auto &item : res)
    {
        cout << "[";
        for (auto &item2 : item)
            cout << item2 << " ";
        cout << "]" << endl;
    }
    cout << endl;
    return 0;
}
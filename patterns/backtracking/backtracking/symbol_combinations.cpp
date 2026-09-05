/**
 * Pattern backtracking.
 *
Given number n, you need to generate all the possible combinations of same pair symbosl ().
It should have the opening and closing symbols in the same pair.
The idea of the optimal solution is to generate all the good combinations from start

Example:
n = 3
result ["((()))", "(()())", "(())()", "()()()"]
 */

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

struct State
{
    string prefix;
    int open_used;
    int close_used;
};

vector<string> generate_symbol_pair_combinations(int n)
{
    // Init the values with the initial value
    queue<State> states;
    states.push({"", 0, 0});

    // Since we are looking for pairs, the size should be 2*n
    // NOTE: Is similar approach on what we are doing in the bruteforce part
    while (!states.empty() && states.front().prefix.size() < 2 * n)
    {
        // So, we are doying backtracking here since we are using a deque to
        // store all the unprocessed values
        State current = states.front();
        states.pop();

        // Now we should generate ALL te combinations with the current state
        if (current.open_used < n)
        {
            states.push({current.prefix + "(", current.open_used + 1, current.close_used});
        }

        if (current.close_used < current.open_used)
        {
            states.push({current.prefix + ")", current.open_used, current.close_used + 1});
        }
    }

    // Format and obtain the result
    vector<string> res;
    while (!states.empty())
    {
        res.push_back(states.front().prefix);
        states.pop();
    }
    return res;
}

int main()
{
    vector<string> res = generate_symbol_pair_combinations(3);

    cout << "Generating symbol pair combinations for 3:" << endl;
    for (auto &item : res)
        cout << item << " ";

    cout << "\n\nGenerating symbol pair combinations for 2:" << endl;
    res = generate_symbol_pair_combinations(2);
    for (auto &item : res)
        cout << item << " ";

    return 0;
}
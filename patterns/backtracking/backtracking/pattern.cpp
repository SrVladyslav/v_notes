/**
 * Pattern backtracking.
 *
 * Time: O(n*4^n / sqrt(n))
 * Memory: O(n*4^n / sqrt(n))
 *
 * 4^n / sqrt(n) is Catalan number, and this is the number of possible combinations
 */

#include <deque>
#include <vector>
#include <string>

using namespace std;

struct State
{
    string prefix;
    int opening;
    int closing;
};

vector<string> generate_bracket_combinations(int n)
{
    // ============================================================================
    // Stage 1: Initialize of the list or deque
    // ============================================================================
    deque<State> queue{{"", 0, 0}};

    // ============================================================================
    // Stage 2: Loop with the stopping condition
    // ============================================================================
    while (true)
    {
        // ============================================================================
        // Stage 3: Get the front element of the queue
        // ============================================================================
        // ...

        // ============================================================================
        // Stage 4: Generating th e valid combination with the final append to the queue
        // THE MAIN PROBLEM IS TO FIGURE OUT WHICH ARE THE VALID SYMBOLS HERE TO GET ONLY THE
        // VALID ONES AND NOW ALL THE COMBINATIONS
        // ============================================================================
        // ...
    }

    vector<string> res;
    for (auto &item : queue)
        res.push_back(item.prefix);

    return res;
}
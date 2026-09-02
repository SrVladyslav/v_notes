/**
 * MANY TIMES THE MONOTONIC STACK IS USED TO SAVE INDICES INSTEAD OF VALUES
 * Time: O(n)
 * Memory: O(n)
 */

#include <vector>
#include <stack>

using namespace std;

vector<int> next_greater(const vector<int> &nums)
{
    // ============================================================================
    // Stage 1: Initialization
    // ============================================================================
    int i = nums.size();
    vector<int> result(nums.size(), -1);
    stack<int> st{};

    // ============================================================================
    // Stage 2: Main loop
    // MAIN PROBLEM IS TO UNDERSTAND IF WE GO FROM LEFT TO RIGHT OR RIGHT TO LEFT
    // ============================================================================
    for (;;)
    {
        // =========================================================================
        // Stage 3: Logic to maintain the monotonic stack (desc or asc order)
        // =========================================================================
        // ...
    }

    return result;
}
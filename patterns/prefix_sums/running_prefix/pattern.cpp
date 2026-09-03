/**
 * Pattern for running prefix sums
 *
 * Time: O(n)
 * Memory: O(1)
 */

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int running_prefix(const vector<int> &nums)
{
    // ============================================================================
    // Stage 1: Initialization
    // ============================================================================
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int left_sum = 0;

    // ============================================================================
    // Stage 2: While loop while searching for the response
    // ============================================================================
    for (int i = 0; i < nums.size(); i++)
    {
        int num = nums[i];

        // ============================================================================
        // Stage 3: Update logic should be ran here,
        // MAIN PROBLEM IS TO UNDERSTAND HOW TO UPDATE THE SUFFIXES
        // AND PREFIXES IN THE VARIABLES
        // ...
        // ============================================================================
    }

    return -1;
}
// This has the same approach like in the pattern of a pointer for everyone
//
// Time: O(n+m)
// Memory: O(max(n, m))

#include <vector>

using namespace std;

vector<vector<int>> multi_segment_intersect(const vector<vector<int>> &seg1, const vector<vector<int>> &seg2)
{
    // ============================================================================
    // Stage 1: Initialization
    // ============================================================================
    vector<vector<int>> result;
    int p1 = 0, p2 = 0;

    // ============================================================================
    // Stage 2: Main loop
    // ============================================================================
    while (p1 < seg1.size() && p2 < seg2.size())
    {
        // Stage 3: Logic for the moving pointers and formatting of the result
        // MAIN PROBLEM IS TO UNDERSTAND WHEN TO MOVE P1 OR P2 AND HOW TO FORM THE RESPONSE
        // ...
    }

    return result;
}
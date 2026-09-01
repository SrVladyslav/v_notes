/**
 * Pattern for segments method
 *
 * Time: O(nlogn)
 * Memory: O(n)
 */

#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> merge(const vector<vector<int>> &segments)
{
    // Stage 1: Sorting, basically we need to sort all the segments by their
    // Starting point
    sort(segments.begin(), segments.end());

    // Stage2: Initialization of the first element for the result
    vector<vector<int>> result{segments[0]};

    // Stage 3: Pass over the oher segments and check for the intersections
    for (int i = 0; i < segments.size(); i++)
    {
        // HERE IS THE MAIN PROBLEM: WHICH IS THE RIGHT WAY TO
        // CREATE THE RESPONSE IN HERE, WHILE OVERPASSING THE OTHER
        // SEGMENTS FROM THE LIST
    }

    return result;
}
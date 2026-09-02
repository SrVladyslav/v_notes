#include <vector>
#include <iostream>
#include <algorithm>
#include "./../utils.h"

using namespace std;

bool is_intersection(const vector<int> &i1, const vector<int> &i2)
{
    return max(i1[0], i2[0]) <= min(i1.back(), i2.back());
}

vector<int> intersect_segments(const vector<int> &s1, const vector<int> &s2)
{
    return {max(s1[0], s2[0]), min(s1.back(), s2.back())};
}

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
        if (is_intersection(seg1[p1], seg2[p2]))
            result.push_back(intersect_segments(seg1[p1], seg2[p2]));

        // Update the pointers
        if (seg1[p1][1] < seg2[p2][1])
            p1++;
        else
            p2++;
    }

    return result;
}

int main()
{
    vector<vector<int>> seg1 = {{1, 2}, {3, 4}, {6, 7}};
    vector<vector<int>> seg2 = {{1, 5}, {7, 8}};
    print_segments(seg1, "\nSegments 1: ");
    print_segments(seg2, "\nSegments 2: ");
    vector<vector<int>> result = multi_segment_intersect(seg1, seg2);
    print_segments(result, "\nIntersections: ");

    return 0;
}
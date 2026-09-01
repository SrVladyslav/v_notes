#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_intersection(const vector<int> &i1, const vector<int> &i2)
{
    return max(i1[0], i2[0]) <= min(i1.back(), i2.back());
}

vector<int> intersect_segments(const vector<int> &s1, const vector<int> &s2)
{
    return {min(s1[0], s2[0]), max(s1.back(), s2.back())};
}

vector<vector<int>> unify_intersections(vector<vector<int>> &segments)
{
    if (segments.size() < 2)
        return segments;

    // Stage 1: Sorting the given segments in order to then check them for intersectiong
    sort(segments.begin(), segments.end());

    // Stage 2: Initialize the first segment in the result part
    vector<vector<int>> result{segments[0]};

    for (int i = 1; i < segments.size(); i++)
    {
        // Stage 3: Check for intersection, if there is intersection, reuse the
        // last segment of a result as current and intersect it with the current
        // position, if is not intersectable, just append to the end, so it will
        // be the next segment.

        if (is_intersection(result.back(), segments[i]))
        {
            result.back() = intersect_segments(result.back(), segments[i]);
        }
        else
        {
            result.push_back(segments[i]);
        }
    }

    return result;
}

int main()
{
    vector<vector<int>> segments{{2, 4}, {1, 3}, {5, 6}, {6, 7}, {8, 8}};

    cout << "Segments: " << endl;
    for (auto segment : segments)
    {
        cout << "[" << segment[0] << " " << segment[1] << "]  ";
    }

    cout << "\nUnified: " << endl;
    for (auto segment : unify_intersections(segments))
    {

        cout << "[" << segment[0] << " " << segment[1] << "]  ";
    }
    return 0;
}
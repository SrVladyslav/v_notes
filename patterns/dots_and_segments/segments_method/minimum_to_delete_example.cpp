/***
 * Given a list of segments. You should find the minimum number of segments which
 * should be deleted, so the remaining ones will not intersect.
 *
 * e.g.
 * segments = [[4,5], [2,6], [1,3], [6,7]]
 * output: 1
 *
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

void print_segments(const vector<vector<int>> &segments, string text = "Segments: ")
{
    cout << text << endl;
    for (auto segment : segments)
    {
        cout << "[" << segment[0] << " " << segment[1] << "]  ";
    }
}

bool is_intersection(const vector<int> &i1, const vector<int> &i2)
{
    return max(i1[0], i2[0]) <= min(i1.back(), i2.back());
}

int min_to_delete(vector<vector<int>> &segments)
{
    if (segments.empty())
        return 0;

    // Stage 1: Sort and save
    sort(segments.begin(), segments.end());

    vector<vector<int>> intersections{segments[0]};
    int intersects = 0;

    for (int i = 1; i < segments.size(); i++)
    {
        if (is_intersection(intersections.back(), segments[i]))
        {
            intersects++;

            // Maintaing the intersection which ends first,
            // since i leaves more space for the short segments.
            // Basically delete the large one and keep the smaller ones.
            if (intersections.back()[1] > segments[i][1])
            {
                intersections.back() = segments[i];
            }
        }
        else
        {
            intersections.push_back(segments[i]);
        }
    }

    return intersects;
}

/**
 * GREEDY RULE: ALWAYS CHOOSE THE SEGMENT THTAT ENDS EARLIEST
 */
int min_to_delete_greedy_classic(vector<vector<int>> &segments)
{
    if (segments.empty())
        return 0;

    // Stage 1: Sorting, but this time we will sort from the last ended,
    // So in case they intersect, we will delete the larger one
    sort(segments.begin(), segments.end(), [](const auto &a, const auto &b)
         { return a[1] < b[1]; });

    // Stage 2: Now just run the segments in order to find the intersections
    int deletions = 0;
    vector<int> current = segments[0];
    for (int i = 1; i < segments.size(); i++)
    {
        if (is_intersection(current, segments[i]))
        {
            deletions++;
        }
        else
        {
            current = segments[i];
        }
    }
    return deletions;
}

int main()
{
    vector<vector<int>> segments{{4, 5}, {2, 6}, {1, 3}, {6, 7}, {7, 8}};
    print_segments(segments);
    int result = min_to_delete(segments);
    cout << "\nMinimum to delete: " << result << endl;

    vector<vector<int>> segments2{{1, 10}, {2, 3}, {4, 5}};
    print_segments(segments2, "\nSegments 2: ");
    result = min_to_delete(segments2);
    cout << "\nMinimum to delete: " << result << endl;

    cout << "\nMinimum to delete clean 1: " << min_to_delete_greedy_classic(segments) << endl;
    cout << "\nMinimum to delete clean 2: " << min_to_delete_greedy_classic(segments2) << endl;

    return 0;
}
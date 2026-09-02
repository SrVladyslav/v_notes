/**
 * Given the meeting hours of two people and the minimum meeting k,
 * we should find the first free meeting slot for both of them.
 *
 * e.g.
 * person1 = [[1,2], [3,4], [7,9]]
 * person1 = [[0,3], [7,8]]
 * k = 2
 *
 * response = [4,6]
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "./../utils.h"

using namespace std;

bool is_intersection(const vector<int> &i1, const vector<int> &i2)
{
    return max(i1[0], i2[0]) <= min(i1.back(), i2.back());
}

vector<int> find_meeting_time(const vector<vector<int>> &seg1, const vector<vector<int>> &seg2, int k)
{
    // ============================================================================
    // Stage 1: Initialization
    // ============================================================================
    vector<int> current{-1, -1};
    int p1 = 0, p2 = 0;
    int last_busy = 0;

    while (p1 < seg1.size() || p2 < seg2.size())
    {
        // ============================================================================
        // Stage 2: Take the next segment cronologically
        // ============================================================================
        if (p2 >= seg2.size() || (p1 < seg1.size() && seg1[p1][0] <= seg2[p2][0]))
        {
            current = seg1[p1];
            p1++;
        }
        else
        {
            current = seg2[p2];
            p2++;
        }

        // ============================================================================
        // Stage 3: Check for free space in the current intersection
        // ============================================================================
        if (current[0] - last_busy >= k)
            return {last_busy, last_busy + k};

        // ============================================================================
        // Stage 4. Update the last busy time
        // ============================================================================
        last_busy = max(current.back(), last_busy);
    }

    return {-1, -1};
}

int main()
{
    vector<vector<int>> person1{{1, 2}, {3, 4}, {7, 9}, {13, 15}};
    vector<vector<int>> person2{{0, 3}, {7, 8}};
    vector<vector<int>> person3{{0, 3}, {4, 5}, {7, 8}, {12, 15}};
    vector<vector<int>> person4{{0, 5}};
    vector<vector<int>> person5{{0, 3}, {8, 10}};
    int k = 2;

    print_segments(person1, "\nPerson 1: ");
    print_segments(person2, "\nPerson 2: ");
    print_segments(person3, "\nPerson 3: ");

    vector<int> result = find_meeting_time(person1, person2, k);
    cout << "\nMeeting time 1-2: " << result[0] << "->" << result[1] << endl;

    result = find_meeting_time(person1, person3, k);
    cout << "Meeting time 1-3: " << result[0] << "->" << result[1] << endl;
    result = find_meeting_time(person1, person3, 1);
    cout << "Meeting time 1-3: " << result[0] << "->" << result[1] << endl;
    result = find_meeting_time(person4, person5, 2);
    cout << "Meeting time 4-5: " << result[0] << "->" << result[1] << endl;

    return 0;
}
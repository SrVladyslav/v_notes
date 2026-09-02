#include <iostream>
#include <vector>
#include <algorithm>
#include "./../utils.h"

using namespace std;

int find_minimum_cabines(const vector<vector<int>> &segments)
{
    // Stage 1: Transform into time slots
    vector<pair<int, int>> times;
    for (const auto &segment : segments)
    {
        times.emplace_back(segment[0], 1);
        times.emplace_back(segment[1], -1);
    }

    // Stage 2: Sort the time slots in ascending order (Chronological)
    sort(times.begin(), times.end(), [](const auto &a, const auto &b)
         {
        if(a.first == b.first) 
            return a.second < b.second; // If they are the same, -1 should o before 1
        return a.first < b.first; });

    // Stage 3: FInd the solution
    int max_cabines = 0;
    int current_cabine = 0;
    for (auto point : times)
    {
        current_cabine += point.second;
        max_cabines = max(max_cabines, current_cabine);
    }

    return max_cabines;
}

int main()
{
    vector<vector<int>> segments{{2, 5}, {1, 3}, {2, 4}};
    print_segments(segments, "Time slots: ");
    int max_cabines = find_minimum_cabines(segments);
    cout << "\nMinimum cabines needed: " << max_cabines << endl;

    return 0;
}
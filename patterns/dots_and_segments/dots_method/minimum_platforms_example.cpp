/**
 * Given some intervals of departures and arrivals in a train station,
 * We should find the minimum platforms so the trains should not wait.
 *
 * e.g.
 * trains = [[9:00, 9:30], [9:15, 12:00], [9:20, 11:30],[11:30, 12:30]]
 * response = 3
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include "./../utils.h"

using namespace std;

int find_minimum_platforms(const vector<pair<float, float>> &timetable)
{
    // Stage 1: Transform into time slots
    vector<pair<float, float>> slots;

    for (const auto &slot : timetable)
    {
        slots.emplace_back(slot.first, 1);
        slots.emplace_back(slot.second, -1);
    }

    // Stage 2: Sort the time slots in ascending order (Chronological)
    sort(slots.begin(), slots.end(), [](const auto &a, const auto &b)
         {
        if (a.first == b.first)
            return a.second < b.second;
        return a.first < b.first; });

    // Stage 3: Find the solution
    int min_concurrent_platforms = 0;
    int current_platform = 0;

    for (auto slot : slots)
    {
        current_platform += slot.second;
        min_concurrent_platforms = max(min_concurrent_platforms, current_platform);
    }

    return min_concurrent_platforms;
}

int main()
{
    vector<pair<float, float>> time_slots{{9.00, 9.30}, {9.15, 12.00}, {9.20, 11.30}, {11.30, 12.30}};
    print_segments(time_slots, "Time slots: ");
    int min_concurrent_platforms = find_minimum_platforms(time_slots);
    std::cout << "\nMinimum platforms needed: " << min_concurrent_platforms << std::endl;

    return 0;
}
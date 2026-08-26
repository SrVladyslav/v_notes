#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int max_ones_with_changes(vector<int> &nums, int k)
{
    int left = 0;
    int right = -1;
    int result = 0;

    // Init the counters to handle the state
    int zeros_counter = 0;

    while (left < nums.size())
    {

        // Increasing right window state
        while (right + 1 < nums.size() && (nums[right + 1] == 1 || zeros_counter < k))
        {
            // Update the zeroes if they exist
            if (nums[right + 1] == 0)
                zeros_counter++;
            right++;
        }

        // Now we should update the values of the result
        result = std::max(result, right - left + 1);

        // Window decreasing state
        if (nums[left] == 0)
            zeros_counter--;
        left++;
    }

    return result;
}

int main()
{
    vector<int> nums{1, 0, 1, 0, 1, 0, 1, 1};
    int k = 2;

    cout << "Array: ";
    for (auto n : nums)
        cout << n << " ";
    cout << "| Number: " << k << '\n';

    int max_ones = max_ones_with_changes(nums, k);

    cout << "Solution: " << max_ones << '\n';

    return 0;
}
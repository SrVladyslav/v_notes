#include <iostream>
#include <vector>

using namespace std;

int find_last_index_for_n(const vector<int> &nums, int target)
{
    // Stage 1: Init the pointers, since we are looking for the last index of,
    // we will have the approach of 0->num.size()
    int left = 0;
    int right = nums.size();

    // Stage 2: Loop over the window
    while (right - left > 1)
    {
        int middle = left + (right - left) / 2;

        // Stage 3: Decrement the middle
        if (nums[middle] <= target)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    // Stage 4: If we are here, then we found the last good index, so let's check for the result
    return nums[left] == target ? left : -1;
}

int main()
{
    vector<int> nums = {1, 2, 6, 6, 9, 10, 11, 13, 14};
    int target = 6;

    cout << "Target: " << target << " | Numbers: " << endl;
    for (int num : nums)
    {
        cout << num << " ";
    }

    int last_good_index = find_last_index_for_n(nums, target);
    cout << "\nLast good index: " << last_good_index << endl;
}
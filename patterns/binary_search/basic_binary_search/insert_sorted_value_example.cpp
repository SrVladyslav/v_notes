/**
 * Given a sorted array of nums and a target value.
 * We should obtain the index in which the target value
 * should be inserted, so that the sorting order is preserved.
 * If we have many positions, then use the last one.
 *
 * e.g.
 * nums = [0,0,1,1,1,3,3,5,8] target = 2 solution = 5
 * nums = [0,0,1,1,1,3,3,5,8] target = 4 solution = 7
 */

#include <iostream>
#include <vector>

using namespace std;

int find_last_index_to_insert(const vector<int> &nums, int target)
{
    // Since we are looking for the first place where the target is greather than
    // the lower number to it and less that the next, we are looking for the first
    // bad position, so we need to use the left=-1 and right=nums.size()-1 approach
    // instead of left=0 and right=nums.size() one.
    int left = -1, right = nums.size() - 1;

    while (right - left > 1)
    {
        int middle = left + (right - left) / 2;

        if (nums[middle] < target)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    return right;
}

int main()
{
    vector<int> nums = {0, 0, 1, 1, 1, 3, 3, 5, 8};
    int target1 = 2;
    int target2 = 4;
    int target3 = -5;
    int target4 = 10;

    cout << "Numbers: " << endl;
    for (int n : nums)
    {
        cout << n << " ";
    }

    int last_good_index = find_last_index_to_insert(nums, target1);
    cout << "\n\nTarget 1: " << target1 << " | Last good index: " << last_good_index << endl;

    last_good_index = find_last_index_to_insert(nums, target2);
    cout << "Target 2: " << target2 << " | Last good index 2: " << last_good_index << endl;

    last_good_index = find_last_index_to_insert(nums, target3);
    cout << "Target 3: " << target3 << " | Last good index 3: " << last_good_index << endl;

    last_good_index = find_last_index_to_insert(nums, target4);
    cout << "Target 4: " << target4 << " | Last good index 4: " << last_good_index << endl;
    return 0;
}
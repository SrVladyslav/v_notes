/**
 * Given a value target and a sorted array of unique numbers nums, where then
 * we moved some times to the ini the last element of the array. We don't know
 * the exact number of times we moved it. What we need to do now is to
 * find the index of the target number in the array.
 *
 * e.g.
 * nums = [4,8,9,1,2]
 * target = 9
 * response = 2
 */

#include <iostream>
#include <vector>

using namespace std;

/**
 * The idea is to use the first binary search to find the last
 * index of the array where we have the moved and the original
 * numbers. So we can use search over the subarray of the elements.
 *
 * THIS WORKS FOR UNIQUE NUMBERS ONLY
 */
int find_array_offset(const vector<int> &nums, int target)
{
    // We need to search for the left right, so will use l=-1, r = len()+1
    // We continue using the last good, first bad pattern.
    // Since we need to check the right part, we set right as size-1
    int left = -1, right = nums.size() - 1;

    while (right - left > 1)
    {
        int middle = left + (right - left) / 2;

        // The compare should work for all the cases in one side of an array
        // Eg: [T,T,T,F,F,F]
        if (nums[middle] > nums.back())
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    return right; // Is left and now the -1, since we are looking where they changed
}

int locate_target_index_binary_search(const vector<int> &nums, int &target, int &left, int &right)
{
    while (right - left > 1)
    {
        int middle = left + (right - left) / 2;

        if (nums[middle] <= target)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }
    return nums[left] == target ? left : -1;
}

int double_binary_search(const vector<int> &nums, int target)

{
    if (nums.empty())
        return -1;

    // Find the offset of the array, where the value are changed
    int offset = find_array_offset(nums, target); // log(n)

    // Now, find the target index number inside the array with the new bounds
    int left, right;
    if (offset == 0)
    {
        // Nothing rotated, so use the full array
        left = 0;
        right = nums.size();
    }
    else if (nums[0] <= target)
    {
        // Means that is in the greather part or the array
        left = 0;
        right = offset;
    }
    else
    {
        // Search for the right part of the array
        left = offset - 1;
        right = nums.size();
    }

    // Now we use the new binary search to find the wanted index inside the boundaries
    return locate_target_index_binary_search(nums, target, left, right);
}

int main()
{
    vector<int> nums = {4, 5, 8, 9, 1, 2, 3};
    int target = 9;

    vector<int> edge_case1 = {2, 3, 4, 5, 1}; // 4
    vector<int> edge_case2 = {1, 2, 3, 4, 5}; // 0
    cout << "Array offset ec 1: " << find_array_offset(edge_case1, target) << endl;
    cout << "Array offset ec 2: " << find_array_offset(edge_case2, target) << endl;

    cout << "\nNumbers: " << endl;
    for (int n : nums)
    {
        cout << n << " ";
    }

    int array_offset = find_array_offset(nums, target);
    cout << "\nArray offset: " << array_offset << endl;
    int result = double_binary_search(nums, target);
    cout << "Result with tg " << target << ": " << result << endl;

    cout << "\nResult EC1 with tg 2: " << double_binary_search(edge_case1, 2) << endl;
    cout << "\nResult EC2 with tg 2: " << double_binary_search(edge_case2, 2) << endl;
    return 0;
}
#include <iostream>
#include <vector>

using namespace std;

int search_first(const vector<int> &nums, int target)
{
    // Since we should find the right part, we will be using the -1 approach and < instead of <=
    int left = -1, right = nums.size() - 1;

    while (right - left > 1)
    {
        int middle = left + (right - left) / 2;

        // NEVER USE LEFT OR RIGHT HERE; AND USE < INSTEAD OF <= in this case
        if (nums[middle] < target)
        {
            left = middle;
        }
        else
        {
            right = middle;
        }
    }

    return nums[right] == target ? right : -1;
}

int search_last(const vector<int> &nums, int target)
{
    // Since here we should find the right part, we are interested in the good left part, so use l=0, r = len
    int left = 0, right = nums.size();

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

pair<int, int> find_first_and_last_index(const vector<int> &nums, int target)
{
    if (nums.empty())
        return {-1, -1};

    return {search_first(nums, target), search_last(nums, target)};
}

int main()
{
    vector<int> nums = {2, 3, 3, 3, 3, 7, 8};
    int target = 3;

    cout << "The numbers are: " << endl;
    for (int n : nums)
    {
        cout << n << " ";
    }

    pair<int, int> result = find_first_and_last_index(nums, target);
    cout << "The indexes for target " << target << " are: " << result.first << " and " << result.second << endl;

    return 0;
}
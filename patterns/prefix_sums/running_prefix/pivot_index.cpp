/**
Given a list of numbers, we need to find an elemnt where all the sums of numbers
before it are equal to the sum of the elements after it.

e.g.
nums = [7,-1, 4, 10, 5, 5]

result = 3.

Since we have the sums before it = 10 and after it also equals 10.
 */

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

/**
 * The base idea of a pivot index is that the prefix sum is updated in
 * each step and we don't save any array for the sums, just calculate it over the run.
 */
int pivot_index(const vector<int> &nums)
{
    // Stage 1: initialization
    int total_sum = accumulate(nums.begin(), nums.end(), 0);
    int prefix_sum = 0;

    // Stage 2: Run over the while loop while looking for the response
    for (int i = 0; i < nums.size(); i++)
    {
        int curr_num = nums[i];

        // Base case
        if (prefix_sum == total_sum - curr_num - prefix_sum)
            return i;

        // Update the prefix sum in order to continue
        prefix_sum += curr_num;
    }

    return -1;
}

int main()
{
    vector<int> nums{7, -1, 4, 10, 5, 5};

    int response = pivot_index(nums);
    cout << "Nums: \n";
    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    cout << "Equal sum: " << response << endl;

    return 0;
}
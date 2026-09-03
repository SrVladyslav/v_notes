/**
 * Given array nums. You should return a new array where each element in position
 * i is a product of all the elements from the array without it.
 *
 * e.g.
 * nums = [1,2,3,4]
 * response = [24,12,8,6]
 */

#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

vector<int> accumulative_product(const vector<int> &nums)
{
    // Step 1: Initialization
    int total_product = accumulate(nums.begin(), nums.end(), 1, std::multiplies<int>());
    vector<int> response(nums.size(), 0);

    // Step 2: Run over the elements obtaining the response
    for (int i = 0; i < nums.size(); i++)
    {
        // Stage 3: Update logic. The problem here was to understand
        // how to update the prefix and the suffixes in the variables
        response[i] = total_product / nums[i];
    }

    return response;
}

int main()
{
    vector<int> nums{1, 2, 3, 4};

    cout << "Nums: \n";
    for (auto num : nums)
        cout << num << " ";
    cout << endl;

    vector<int> response = accumulative_product(nums);

    cout << "Response: \n";
    for (auto num : response)
        cout << num << " ";
    cout << endl;
    return 0;
}
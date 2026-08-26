#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

vector<string> group_numbers(const vector<int> &nums)
{
    vector<string> groups;
    int left = 0;
    int right = 0;

    while (left < nums.size())
    {
        // We should explotre the right boundary with the inner loop
        while (right + 1 < nums.size() && nums[right] + 1 == nums[right + 1])
        {
            right++;
        }

        // If we are here, it means that the cndition is not met,
        // so basically we need to add the group to the solution
        if (right != left)
        {
            groups.push_back(to_string(nums[left]) + "->" + to_string(nums[right]));
        }
        else
        {
            groups.push_back(to_string(nums[left]));
        }

        // Now we wanna move one step to the right and continue
        left = right + 1;
        right = right + 1;
    }

    return groups;
}

int main()
{
    vector<int> input_data{1, 2, 3, 5, 8, 9, 14};

    cout << "Input: ";
    for (auto n : input_data)
        cout << n << " ";

    auto groups = group_numbers(input_data);
    cout << "\nSolution: ";
    for (auto g : groups)
        cout << g << " ";

    return 0;
}
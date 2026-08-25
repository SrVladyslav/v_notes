#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>

using namespace std;

pair<vector<int>, int> read_input()
{
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cerr << "Could not open input.txt\n";
        exit(1);
    }

    string line;
    getline(file, line);

    replace(line.begin(), line.end(), ',', ' ');

    stringstream ss(line);

    vector<int> nums;
    int n;

    while (ss >> n)
        nums.push_back(n);

    int target;
    file >> target;

    return {nums, target};
}

int max_sum_k_numbers(const vector<int> &nums, int k)
{
    // initialization of the first window sum
    int window_sum = 0;
    for (int i = 0; i < k; i++)
    {
        window_sum += nums[i];
    }

    // Initialization of the max current sum
    int max_sum = window_sum;

    // Best approach
    for (int right = k; right < nums.size(); right++)
    {
        window_sum = window_sum - nums[right - k] + nums[right];
        max_sum = std::max(max_sum, window_sum);
    }

    return max_sum;
}

int main()
{
    auto [nums, k] = read_input();

    cout << "Array: ";
    for (auto n : nums)
    {
        cout << n << " ";
    }
    cout << "| Number: " << k << '\n';

    int max_sum = max_sum_k_numbers(nums, k);
    cout << "Solution: " << max_sum << '\n';

    vector<int> nums2{3, 2, 0, 9, 1, 2, 8, 5, 2};
    k = 5;
    cout << "Array: ";
    for (auto n : nums2)
    {
        cout << n << " ";
    }
    cout << "| Number: " << k << '\n';
    max_sum = max_sum_k_numbers(nums2, 5);
    cout << "Solution: " << max_sum << '\n';

    return 0;
}
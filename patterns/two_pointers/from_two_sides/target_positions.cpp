#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
// g++ -std=c++23 -static target_positions.cpp -o main.exe

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

pair<int, int> target_positions(vector<int> &nums, int target)
{
    int l = 0;
    int r = nums.size() - 1;

    while (l < r)
    {
        int curr_sum = nums[l] + nums[r];

        if (curr_sum == target)
            return {l, r};
        else if (curr_sum < target)
            l++;
        else
            r--;
    }

    return {-1, -1};
}

int main()
{
    auto [nums, target] = read_input();

    cout << "Array: ";
    for (int n : nums)
        cout << n << ' ';

    cout << "\nTarget: " << target << '\n';

    auto [a, b] = target_positions(nums, target);
    cout << "Solution: " << a << " " << b << '\n';

    return 0;
}
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

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

void move_all_n_to_end(vector<int> &nums, int &n)
{
    int p_fast = 0;
    int p_slow = 0;

    while (p_fast < nums.size())
    {
        if (nums[p_fast] != n)
        {
            std::swap(nums[p_slow], nums[p_fast]);
            p_slow++;
        }

        p_fast++;
    }
}

int main()
{
    auto [nums, n] = read_input();

    cout << "Array: ";
    for (auto n : nums)
        cout << n << ' ';

    cout << "| Number: " << n << '\n';

    move_all_n_to_end(nums, n);

    cout << "Solution: ";
    for (auto n : nums)
        cout << n << ' ';

    return 0;
}

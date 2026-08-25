#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;
// g++ -std=c++23 -static target_positions.cpp -o main.exe

pair<vector<int>, vector<int>> read_input()
{
    ifstream file("input.txt");
    if (!file.is_open())
    {
        cerr << "Could not open input.txt\n";
        exit(1);
    }

    // Read the first line
    string line1;
    getline(file, line1);
    replace(line1.begin(), line1.end(), ',', ' ');
    stringstream ss1(line1);

    vector<int> nums_a;
    int n;
    while (ss1 >> n)
    {
        nums_a.push_back(n);
    }

    // Read the second line
    string line2;
    getline(file, line2);
    replace(line2.begin(), line2.end(), ',', ' ');
    stringstream ss2(line2);

    vector<int> nums_b;
    while (ss2 >> n)
    {
        nums_b.push_back(n);
    }

    return {nums_a, nums_b};
}

vector<int> intersection(vector<int> &a, vector<int> &b)
{
    vector<int> result;
    int p1 = 0;
    int p2 = 0;

    while (p1 < a.size() && p2 < b.size())
    {
        if (a[p1] < b[p2])
        {
            p1++;
        }
        else if (b[p2] < a[p1])
        {
            p2++;
        }
        else
        {
            result.push_back(a[p1]);
            p1++;
            p2++;
        }
    }
    return result;
}

int main()
{
    auto [a, b] = read_input();

    cout << "Array A: ";
    for (int n : a)
        cout << n << ' ';

    cout << "| Array B: ";
    for (int n : b)
        cout << n << ' ';

    auto solution = intersection(a, b);
    cout << "\nSolution: ";
    for (int n : solution)
        cout << n << ' ';

    return 0;
}
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

string sort_by_frequency(const string &input_data)
{
    // Stage 1: KV counting part
    unordered_map<char, int> counter;
    for (char c : input_data)
    {
        counter[c]++;
    }

    // Stage 2: VK, basically do the inversion and count the by freq groups
    vector<vector<char>> frequency_list(input_data.size() + 1);
    for (const auto &[symbol, frequency] : counter)
    {
        frequency_list[frequency].push_back(symbol);
    }

    // Stage 3: Creating the result from the frequncy list
    string result;
    result.reserve(input_data.size());
    for (int i = frequency_list.size() - 1; i > 0; i--)
    {
        for (char c : frequency_list[i])
        {
            result.append(i, c);
        }
    }

    return result;
}

int main()
{
    string input_data = "BABBCBC";
    cout << "Input data: " << input_data << endl;
    string result = sort_by_frequency(input_data);
    cout << "Result: " << result << endl;

    return 0;
}
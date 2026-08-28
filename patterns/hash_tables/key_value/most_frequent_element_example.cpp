/**
 * Given a list of numbers nums and number k.
 * We should return the k most frequent numbers in the list.
 *
 * Example:
 * nums = [5,8,5,5,4,4,5], k = 2
 * Output: [5,4]
 */

#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

// This approach wiil be the Hash Table KV approach too, just for the sake of example
vector<int> most_frequent_elements(const vector<int> &nums, const int k)
{
    // Stage 1: counting the frequencies
    unordered_map<int, int> freq_counter;
    for (int num : nums)
    {
        freq_counter[num]++;
    }

    // Stage 2: Invert the frequencies into a list of lists, so we can
    // Sort the numbers per frequency
    vector<vector<int>> frequency_list(nums.size() + 1); // Init with the nums vector size
    for (const auto &[num, freq] : freq_counter)
    {
        frequency_list[freq].push_back(num);
    }

    // Stage 3: Create the result from the most common to the least common one
    vector<int> result;
    result.reserve(k); // Reserve the space for the k wanted results only

    for (int i = frequency_list.size() - 1; i > 0; i--)
    {
        for (const auto &num : frequency_list[i])
        {
            if (result.size() >= k)
                return result;

            result.push_back(num);
        }
    }
    return result;
}

int main()
{
    vector<int> nums = {5, 8, 5, 5, 4, 4, 5};
    int k = 2;

    cout << "Input: ";
    for (int num : nums)
    {
        cout << num << " ";
    }

    cout << "\nMost frequent elements: ";
    vector<int> result = most_frequent_elements(nums, k);
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
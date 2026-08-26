/**
 * Given string s and value k. Find the longest unique substring, which contains no
 * more than k characters. Return its length.
 *
 * e.g.
 * s = "aabacbebebe", k = 3
 * Solution = 7
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/**
 * Here we are using again the overlapping window pattern, but we
 * should also need to use the dictionary for counters.
 */
int longest_str(const string &str, int k)
{
    if (k <= 0)
        return 0;

    int left = 0;
    int right = -1;
    int result = 0;

    // Init the window state:Hw many times the char appears in the current window
    std::unordered_map<char, int> change_counters;
    int unique_chars = 0; // How many different actors are in the current window, we can also use change_counters.size()

    while (left < static_cast<int>(str.size()))
    {
        // Widen the window
        while (right + 1 < static_cast<int>(str.size()) && (change_counters.contains(str[right + 1]) || unique_chars < k))
        {
            // Window state update
            if (change_counters[str[right + 1]] == 0)
                unique_chars++;
            change_counters[str[right + 1]]++;
            right++;
        }

        // Update the max result for the given right + 1 string
        result = std::max(result, right - left + 1);

        // Decrease the window size
        change_counters[str[left]]--;

        if (change_counters[str[left]] == 0)
        {
            change_counters.erase(str[left]);
            unique_chars--;
        }
        left++;
    }

    return result;
}

int main()
{
    string str = "aabacbebebe";
    int k = 3;
    cout << "String: " << str << " | Number: " << k << '\n';

    int max_str = longest_str(str, k);
    cout << "Solution: " << max_str << '\n';

    return 0;
}
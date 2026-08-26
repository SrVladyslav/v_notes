#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

/**
 * Given a list of symbols, you should compress it, by changing the repeated symbold by
 * the symbol and their number of appearances. If the symbol, appears only one time,
 * we should not add the quantity number at the end of it.
 *
 * e.g.
 * chars = ["a","a", "b", "c", "c", "c", "c"]
 * response: ["a", "2", "b", "c", "4"]
 */

vector<string> compress(vector<string> &chars)
{
    vector<string> compressed;
    int left = 0;
    int right = 0;
    int counter;

    while (left < chars.size())
    {
        // We will be running over the right boundary and checking
        // for the repeated symbold while adding them
        counter = 1; // We always start with one symbol which is where two counters are pointing
        while (right + 1 < chars.size() && chars[right] == chars[right + 1])
        {
            right++;
            counter++; // We count the symbols to be added at the end
        }

        // Now the symbols changed, so we basically need to add them into the solution list
        if (counter > 1)
        {
            compressed.push_back(chars[left]);
            compressed.push_back(to_string(counter));
        }
        else
        {
            compressed.push_back(chars[left]);
        }

        // Now we need to jump to the another window
        left = right + 1;
        right = right + 1;
        counter = 0;
    }

    return compressed;
}

int main()
{
    vector<string> chars{"a", "a", "b", "c", "c", "c", "c"};

    cout << "Input: ";
    for (auto c : chars)
        cout << c << " ";

    auto compressed = compress(chars);
    cout << "\nSolution: ";
    for (auto c : compressed)
        cout << c << " ";

    return 0;
}
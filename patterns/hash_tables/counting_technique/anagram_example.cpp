/**
 * Given two strings s and t. We need to check if t is an anagram of s.
 * Basically if is possible to rearrange the chars of t in the same order as the s.
 *
 * e.g
 * s="ABCC"
 * t ="CBAC"
 * Solution = true
 */

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

/**
 * Time: O(n+m) -> O(n)
 * Memory: O(k) where k is the number of unique chars
 */
bool can_make_anagram(const string &s, const string &t)
{

    /**
     * PD: We can exit even before by checking the lengths, but thsi is an example for the pattern
     * so we do not need to do it here.
     *
     * if(s.size() != t.size())
     *     return false;
     */
    // Counting stage
    unordered_map<char, int> counter;

    for (const char &c : s)
    {
        counter[c]++; // Add basically the frequency of every char in the first string
    }

    // Now go throug the second string and quit the chars
    for (const char &c : t)
    {
        if (counter[c] == 0)
            return false; // If the char is not in the counter, then it is not an anagram and we can skip the next step
        counter[c]--;     // Decrease the counter
    }

    // Now we loop over the counter and check if the value is 0 or not
    for (const auto &[_, frequency] : counter)
    {
        if (frequency != 0)
            return false;
    }
    return true;
}

int main()
{
    string s = "ABCC";
    string t = "CBAC";
    string u = "ABC";

    cout << "String 1: " << s << " | String 2: " << t << " | String 3: " << u << '\n';
    cout << "Solution 1-2: " << (can_make_anagram(s, t) ? "YES" : "NO") << '\n';
    cout << "Solution 1-3: " << (can_make_anagram(s, u) ? "YES" : "NO") << '\n';

    return 0;
}
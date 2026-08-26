#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

bool is_palindrome_permutation(const string &chars)
{
    // Counting the char frequency in the string
    unordered_map<char, int> char_frequency;

    for (char c : chars)
    {
        char_frequency[c]++;
    }

    // Now we should check if the odd numbers are 0 or 1, if is more then palindrome is impossible
    int odd_counter = 0;

    for (const auto &[_, freq] : char_frequency)
    {
        if (freq % 2 == 1)
            odd_counter++;
    }
    return odd_counter <= 1;
}

int main()
{
    string good_chars = "aabaaba";
    string bad_chars = "abc";

    cout << "Chars: " << good_chars << " | Solution: " << (is_palindrome_permutation(good_chars) ? "YES" : "NO") << '\n';
    cout << "Chars: " << bad_chars << " | Solution: " << (is_palindrome_permutation(bad_chars) ? "YES" : "NO") << '\n';

    return 0;
}
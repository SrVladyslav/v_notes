/**
 * Given two string s and t. We need to return true, if the strings
 * will be identical after removing all the special symbols. The symbol #
 * is used to mark that this and the previoud char should be removed.
 * If there is nothing before #, it should delete nothing from before.
 *
 * e.g.
 * s = "ab#c"
 * t = "ad#c"
 *
 * output = True
 */

#include <iostream>
#include <string>

using namespace std;

bool redact(string &s, string &t)
{
    int i = s.size() - 1, j = t.size() - 1;

    while (i >= 0 || j >= 0)
    {
        int skip_s = 0, skip_t = 0;

        // Find nex tvalid char in s
        while (i >= 0)
        {
            if (s[i] == '#')
            {
                skip_s++;
                i--;
            }
            else if (skip_s > 0)
            {
                skip_s--;
                i--;
            }
            else
            {
                break;
            }
        }

        // Find next valid char in t
        while (j >= 0)
        {
            if (t[j] == '#')
            {
                skip_t++;
                j--;
            }
            else if (skip_t > 0)
            {
                skip_t--;
                j--;
            }
            else
            {
                break;
            }
        }

        // one string still has a valid char, the other doesn't
        if ((i >= 0) != (j >= 0))
            return false;

        // Both string have a valid chars
        if (i >= 0 && s[i] != t[j])
            return false;

        i--;
        j--;
    }

    return true;
}

int main()
{
    string s = "ab#c";
    string t = "ad#c";
    string test = "abra";

    cout << "s: " << s << endl;
    cout << "t: " << t << endl;
    cout << "test: " << test << endl;

    cout << "Result s -> t: " << (redact(s, t) ? "True" : "False") << endl;
    cout << "Result t -> s: " << (redact(t, s) ? "True" : "False") << endl;
    cout << "Result test -> s: " << (redact(test, s) ? "True" : "False") << endl;
    return 0;
}
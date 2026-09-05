/**
Given a string with two numbers in it from 1 to 9.
Every number has a combination of characters in it,
you are tasked with finding all possible combinations of characters.

Example:

input = "24"
output = ["ag","ah", "ai","bg","bh","bi", "cg","ch","ci"]

For the solution, we will start with a first item from the nums iput,
then will bruteforce all thecombinations and add them to the list again,
finally if the next item has the same number of characters, is the response
 */

#include <unordered_map>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<string> generate_combinations(string &str)
{
    unordered_map<char, string> phone_map{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};

    // First what we should do it to create the response structure with one element ""
    vector<string> result{""};

    // Now we add the loop to bruteforce the combinations
    while (!result.empty() && result.front().length() < str.length())
    {
        // We need to get the combinations of the elements while the size of them is not equal to the asking str
        string prefix = result.front();
        result.erase(result.begin());

        // Now we should obtain the next digit from str to process
        // NOTE: PREFIX LENGTH = DIGIT QUANTITY ALREADY PROCESSED
        char digit = str[prefix.size()];

        // Now we should generate the bruteforce of all the combinations with that digit
        for (char &letter : phone_map[digit])
        {
            result.push_back(prefix + letter);
        }
    }
    return result;
}

int main()
{
    string combination = "24";

    cout << "Combinations for " << combination << ": ";
    vector<string> res = generate_combinations(combination);
    for (auto &item : res)
        cout << item << " ";

    return 0;
}
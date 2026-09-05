/**
 * Pattern bruteforce.
 *
Given a string with two numbers in it from 1 to 9.
Every number has a combination of characters in it,
you are tasked with finding all possible combinations of characters.

Example:

input = "24"
output = ["ag","ah", "ai","bg","bh","bi", "cg","ch","ci"]

For the solution, we will start with a first item from the nums iput,
then will bruteforce all thecombinations and add them to the list again,
finally if the next item has the same number of characters, is the response



Every str symbol has a max of 4 chars -> 4^n combinations, but every combination has 4 more symbols, so:

Time: O(n+4^2n)
Memory: O(n*4^n)

*/

#include <deque>
#include <unordered_map>
#include <string>
#include <vector>

using namespace std;

vector<string> generate_combinations(string &str)
{
    unordered_map<int, string> phone_map{
        {2, "abc"}, {3, "def"}, {4, "ghi"}, {5, "jkl"}, {6, "mno"}, {7, "pqrs"}, {8, "tuv"}, {9, "wxyz"}};

    // ============================================================================
    // Stage 1: Initialize the queue or deque. Queue inside has the deque
    // ============================================================================
    deque<string> result{{""}};

    // ============================================================================
    // Stage 2: Loop with the condition to stop the brute force
    // ============================================================================
    while (true) // BASE PROBLEM IS TO FIND THE WHILE CONDITION AND THE COMBINATION GENERATION
    {
        // ============================================================================
        // Stage 3: We get the first element of the queue
        // ============================================================================
        string current = result.front();

        // ============================================================================
        // Stage 4: Generating all the combinations and the final push back to the queue
        // ============================================================================
    }

    vector<string> res;
    for (auto &item : result)
        res.push_back(item);

    return res;
}
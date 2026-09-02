#include <iostream>
#include <stack>
#include <vector>
#include <unordered_map>
#include "./utils.h"

using namespace std;

bool is_valid(const vector<char> &symbols)
{
    // Stage 1: Initialization
    stack<char> _stack;
    unordered_map<char, char> patterns = {{'(', ')'}, {'[', ']'}, {'{', '}'}, {'<', '>'}};

    // Stage 2: Main loop
    for (char symbol : symbols)
    {
        if (patterns.contains(symbol))
            _stack.push(symbol); // Is opening symbol since is in the map, so add to stack and continue
        else if (_stack.empty())
            return false; // Is a closing symbol since is no in the map, so is not valid
        else
        {
            char head = _stack.top(); // Obtain the head element
            _stack.pop();             // Now remove the head element since we have its value

            if (symbol != patterns[head])
                return false;
        }
    }
    return _stack.empty();
}

int main()
{
    vector<char> symbols = {'(', ')', '<', '[', '{', '}', ']', '>'};
    vector<char> bad_symbols = {'(', '(', ')'};

    pprint(symbols);
    cout << "Is valid: " << (is_valid(symbols) ? "True" : "False") << endl;

    pprint(bad_symbols);
    cout << "Is valid: " << (is_valid(bad_symbols) ? "True" : "False") << endl;

    return 0;
}
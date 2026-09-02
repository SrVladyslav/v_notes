/*
Given a list of same symbols, we need to check if every opening symbol
has its closing symbol.

e.g.
symbols = ["(",")","(","(",")",")"]
output = True

symbols = ["(","(",")"]
output = False

This approach really does not need the stack, we can just use a counter kek.
*/
#include <iostream>
#include <vector>

using namespace std;

bool is_valid(const vector<char> &symbols)
{
    int counter = 0;

    for (char symbol : symbols)
    {
        if (symbol == '(')
            counter++;
        else
            counter--;

        // Fast exit
        if (counter < 0)
            return false;
    }

    return counter == 0;
}

int main()
{
    vector<char> symbols = {'(', ')', '(', '(', ')', ')'};
    vector<char> bad_symbols = {'(', '(', ')'};

    cout << "Symbols: " << endl;
    for (char symbol : symbols)
    {
        cout << symbol << " ";
    }

    cout << "\nIs valid: " << (is_valid(symbols) ? "True" : "False") << endl;

    cout << "\nBad symbols: " << endl;
    for (char symbol : bad_symbols)
    {
        cout << symbol << " ";
    }

    cout << "\nIs valid: " << (is_valid(bad_symbols) ? "True" : "False") << endl;
}
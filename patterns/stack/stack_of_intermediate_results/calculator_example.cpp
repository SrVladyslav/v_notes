/**
 * We are given with an expression inside tokens. We need to solve it.
 *
 * e.g.
 * tokens = ["2", "3", "1", "-", "*"]
 * output = 4
 */

#include <iostream>
#include <stack>
#include <vector>
#include <string>
#include <unordered_map>
#include "./utils.h"

using namespace std;

float apply_operation(const float &a, const float &b, const char &op)
{
    switch (op)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case '/':
        return a / b;
    default:
        return 0;
    }
}

/**
 * The approach will be using the stack intermediate results approach,
 * we will stack all the numbers and then if some operation is found,
 * we will pop two numbers from the stack, apply the opratioln and push it back.
 */
float calculate(const vector<char> &tokens)
{
    // Stage 1: Initialization
    stack<float> st; // Only numbers will be stored here
    // We can use isdigit to check if the char is a digit, but here we are just folowing the general schema for POC purposes
    unordered_map<char, char> operators = {{'+', '+'}, {'-', '-'}, {'*', '*'}, {'/', '/'}};

    // Stage 2: Main loop
    for (char token : tokens)
    {
        if (operators.contains(token))
        {
            if (st.size() < 2)
                return -1;

            float b = st.top();
            st.pop();
            float a = st.top();
            st.pop();

            float operation = apply_operation(a, b, token);
            cout << a << token << b << " = " << operation << endl;
            st.push(operation);
        }
        else
        {
            st.push(stof(string(1, token)));
        }
    }

    return st.empty() ? -1 : st.top();
}

int main()
{
    vector<char> tokens{'2', '3', '1', '-', '*'};
    pprint(tokens);

    float result = calculate(tokens);
    cout << "Result: " << result << endl;

    return 0;
}
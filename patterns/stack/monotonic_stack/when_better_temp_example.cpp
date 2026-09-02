/**
 * We are given with a termperatures array. For each day we need to find
 * in how many days the temperature will be greater. If is impossible, return 0.
 *
 * e.g.
 * temperatures = [10,9,8,15,20,12]
 * res = [3,2,1,1,0,0]
 */

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

/**
 * MANY TIMES THE MONOTONIC STACK IS USED TO SAVE INDICES INSTEAD OF VALUES
 */
vector<int> finf_better_temp(const vector<int> &temperatures)
{
    // Stage 1: Initialization
    stack<int> st;
    vector<int> result(temperatures.size(), 0);

    for (int i = temperatures.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && temperatures[i] >= temperatures[st.top()])
        {
            st.pop();
        }

        if (!st.empty())
        {
            result[i] = st.top() - i;
        }

        st.push(i);
    }

    return result;
}

int main()
{
    vector<int> temperatures = {10, 9, 8, 15, 20, 12};
    cout << "Temperatures: " << endl;
    for (int num : temperatures)
    {
        cout << num << " ";
    }
    vector<int> result = finf_better_temp(temperatures);
    cout << "Result: " << endl;
    for (int num : result)
    {
        cout << num << " ";
    }
}
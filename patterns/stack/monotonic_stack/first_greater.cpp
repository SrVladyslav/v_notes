#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<int> find_greaters(const vector<int> &nums)
{
    // Stage 1: initialization
    stack<int> st;
    vector<int> result(nums.size(), -1);

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[i] >= st.top())
            st.pop();

        if (!st.empty())
            result[i] = st.top();

        st.push(nums[i]);
    }

    return result;
}

int main()
{
    vector<int> nums = {2, 5, 1, 3, 0, 4};
    cout << "Numbers: " << endl;
    for (int num : nums)
    {
        cout << num << " ";
    }

    vector<int> result = find_greaters(nums);
    cout << "Result: " << endl;
    for (int num : result)
    {
        cout << num << " ";
    }

    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> unify_segments(vector<int> seg1, vector<int> seg2)
{
    if (seg1.size() < 1 || seg2.size() < 1)
        return {};

    vector<int> result;

    result.push_back(min(seg1[0], seg2[0]));
    result.push_back(max(seg1.back(), seg2.back()));

    return result;
}

int main()
{
    vector<int> i1 = {1, 5};
    vector<int> i2 = {4, 10};

    cout << "Union: " << endl;
    for (auto i : unify_segments(i1, i2))
        cout << i << " ";
    return 0;
}
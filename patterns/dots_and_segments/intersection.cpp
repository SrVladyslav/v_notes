
#include <algorithm>
#include <vector>
#include <iostream>

using namespace std;

bool intersects(const vector<int> &i1, const vector<int> &i2)
{
    if (i1.size() < 1 || i2.size() < 1)
        return false;

    return max(i1[0], i2[0]) <= min(i1.back(), i2.back());
}

int main()
{
    vector<int> i1 = {1, 5};
    vector<int> i2 = {4, 10};

    cout << "Intersection: " << intersects(i1, i2) << endl;
    return 0;
}
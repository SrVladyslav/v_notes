/**
 * Here we just explain how to implement the prefix sums using a list and what it is.
 *
 * e.g.
 * nums = [1,4,5,-3,7,2]
 * prefix = [0,1,5,10,7,14,16]
 *
 * Meaning that pefix 4 for example, has the sum of all the numbers before it,
 * so we can find the sum of all the numbers before 4 by using prefix[4] and do not
 * need to iterate over the whole list. We can also obtaine the sums over a window in O(1).
 */

#include <vector>
#include <iostream>
using namespace std;

class PrefixList
{
public:
    PrefixList(const vector<int> &nums)
    {
        prefix.resize(nums.size() + 1);
        prefix[0] = 0;
        for (int i = 0; i < nums.size(); i++)
            prefix[i + 1] = prefix[i] + nums[i];
    }

    int sum(int left, int right)
    {
        if (right >= prefix.size())
            return 0;

        return prefix[right + 1] - prefix[left];
    }

private:
    vector<int> prefix;
};

int main()
{
    vector<int> nums{1, 4, 5, -3, 7, 2};

    PrefixList prefix(nums);

    std::cout << "Prefix sum 2-5: " << prefix.sum(2, 5) << std::endl;
    std::cout << "Prefix sum 1-3: " << prefix.sum(1, 3) << std::endl;
    std::cout << "Prefix sum 0-3: " << prefix.sum(0, 3) << std::endl;

    return 0;
}
#include <vector>
using namespace std;

/**
 * Implementation of the prefix list, so it can be reused elsewhere.
 */
class PrefixArray
{
public:
    PrefixArray(const vector<int> &nums)
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
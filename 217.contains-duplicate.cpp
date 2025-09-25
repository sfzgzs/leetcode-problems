#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    bool containsDuplicate(std::vector<int> &nums)
    {
        std::unordered_set<int> myset(nums.begin(), nums.end());
        if (nums.size() == myset.size())
            return false;
        else
            return true;
    }
};
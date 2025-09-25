#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    // 74 ms
    // bool containsDuplicate(std::vector<int> &nums)
    // {
    //     std::unordered_set<int> myset(nums.begin(), nums.end());
    //     if (nums.size() == myset.size())
    //         return false;
    //     else
    //         return true;
    // }

    // 55 ms
    bool containsDuplicate(std::vector<int> &nums)
    {
        unordered_set<int> mymap;
        for (int i = 0; i < nums.size(); i++)
        {
            int size = mymap.size();
            mymap.insert(nums[i]);
            if (mymap.size() == size)
                return true;
        }
        return false;
    }
};
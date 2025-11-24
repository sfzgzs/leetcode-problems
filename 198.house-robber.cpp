#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> gain = {0};
    int rob(vector<int> &nums)
    {
        gain.push_back(nums[0]);

        while (gain.size() <= nums.size())
        {
            int gsize = gain.size();
            gain.push_back(max(gain[gsize - 2] + nums[gsize - 1], gain[gsize - 1]));
        }
        return gain[nums.size()];
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 2, 2};
    auto res = s.rob(nums);
    cout << "RESULT" << res << endl;
}

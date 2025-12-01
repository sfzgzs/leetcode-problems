#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    int findMin(vector<int> &nums)
    {
        if (nums.size() == 1)
            return nums[0];
        if (nums.size() == 2)
            return min(nums[0], nums[1]);

        vector<int> l(nums.begin(), nums.begin() + nums.size() / 2);
        int left = findMin(l);
        vector<int> r(nums.begin() + nums.size() - (nums.size() / 2) - 1, nums.end());

        int right = findMin(r);
        return min(left, right);
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 2};
    auto res = s.findMin(nums);
    cout << res << endl;
}

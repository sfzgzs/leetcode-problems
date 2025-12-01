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
        int res = nums[0];
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            if (nums[l] < nums[r])
            {
                res = min(res, nums[l]);
                break;
            }
            int mid = (l + r) / 2;
            res = min(res, nums[mid]);
            if (nums[mid] >= nums[l])
                l = m + 1;
            else
                r = mid - 1;
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {3, 4, 5, 1, 2};
    auto res = s.findMin(nums);
    cout << res << endl;
}

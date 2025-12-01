#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    int search(vector<int> &nums, int target)
    {
        int l = 0;
        int r = nums.size() - 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;

            // case of sorted
            if (nums[l] <= nums[mid])
            {
                if (target < nums[l] || target > nums[mid])
                    l = mid + 1;
                else
                    r = mid - 1;
            }
            else
            {
                if (target < nums[mid] || target > nums[r])
                    r = mid - 1;
                else
                    l = mid + 1;
            }
        }
        return -1;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 3};
    auto res = s.search(nums, 2);
    cout << res << endl;
}

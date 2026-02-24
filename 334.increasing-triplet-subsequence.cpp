#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;
class Solution
{
public:
    bool increasingTriplet(vector<int> &nums)
    {
        if (nums.size() < 3)
            return false;

        int min = nums[0];
        int mid = INT_MAX;

        for (int current : nums)
        {
            if (current <= min)
            {
                min = current;
            }
            else if (current <= mid)
            {
                mid = current;
            }
            else
                return true;
        }
        return false;
    }
};
int main()
{
    Solution s;
    vector<int> all = {20, 100, 10, 12, 5, 13};
    cout << s.increasingTriplet(all);
}
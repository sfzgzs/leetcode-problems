#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
public:
    int longestSubarray(vector<int> &nums)
    {
        vector<int> zeros;
        for (int i = 0; i < nums.size(); i++)
        {
            if (!nums[i])
                zeros.push_back(i);
        }
        if (nums.size() == 1)
            return 0;
        if (zeros.size() <= 1)
            return nums.size() - 1;
        zeros.insert(zeros.begin(), -1);
        zeros.push_back(nums.size());
        int m = -1;
        for (int i = 1; i + 1 < zeros.size(); i++)
        {
            int currentlen = zeros[i + 1] - zeros[i - 1] - 2;
            m = max(m, currentlen);
        }
        return m;
    }
};
int main()
{
    Solution s;
    vector<int> all = {0, 1, 1, 1, 0, 1, 1, 0, 1};
    cout << s.longestSubarray(all);
}
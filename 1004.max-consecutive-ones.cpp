#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{
public:
    int longestOnes(vector<int> &nums, int k)
    {
        vector<int> zeros;

        for (int i = 0; i < nums.size(); i++)
            if (nums[i] == 0)
                zeros.push_back(i);

        if (zeros.size() <= k)
            return nums.size();

        // add boundaries
        zeros.insert(zeros.begin(), -1);
        zeros.push_back(nums.size());

        int maxsize = 0;

        for (int i = 1; i + k < zeros.size(); i++)
        {
            int left = zeros[i - 1];
            int right = zeros[i + k];

            int size = right - left - 1;
            maxsize = max(maxsize, size);
        }

        return maxsize;
    }
};
int main()
{
    vector<int> all = {1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 0};
    Solution s;
    cout << s.longestOnes(all, 2);
}
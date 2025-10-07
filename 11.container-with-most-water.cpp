#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <queue>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int maxnum = *max_element(height.begin(), height.end());
        int i = 0, j = height.size() - 1;
        int max = 0;
        while (i < j && maxnum * (j - i) > max)
        {
            int min = std::min(height[i], height[j]);
            max = std::max(min * (j - i), max);
            if (height[i] == min)
                i++;
            else
                j--;
        }
        return max;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 7, 2, 5, 4, 7, 3, 6};
    auto res = s.maxArea(nums);
    cout << res << endl;
}
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int trap(vector<int> &height)
    {
        vector<int> right({height[height.size() - 1]});
        vector<int> left({height[0]});

        for (int i = 1; i < height.size(); i++)
        {
            if (height[i] > left[i - 1])
                left.push_back(height[i]);
            else
                left.push_back(left[i - 1]);
        }
        for (int i = 1; i < height.size(); i++)
        {
            if (height[height.size() - 1 - i] > right[i - 1])
                right.push_back(height[height.size() - 1 - i]);
            else
                right.push_back(right[i - 1]);
        }
        int sum = 0;
        for (int i = 0; i < height.size(); i++)
        {
            int mi = min(left[i], right[height.size() - 1 - i]);
            if (mi - height[i] > 0)
                sum += mi - height[i];
        }
        return sum;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    auto res = s.trap(nums);
    cout << "RESULT" << res << endl;
}

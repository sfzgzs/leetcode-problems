#include <string>
#include <iostream>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<int> productExceptSelf(vector<int> &nums)
    {
        vector<int> left(nums.size(), 1);
        vector<int> right(nums.size(), 1);

        for (int i = 1; i < nums.size(); i++)
            left[i] = left[i - 1] * nums[i - 1];
        for (int i = nums.size() - 2; i >= 0; i--)
            right[i] = right[i + 1] * nums[i + 1];

        for (int i = 0; i < nums.size(); i++)
        {
            left[i] *= right[i];
        }
        return left;
    }
};
int main()
{
    Solution s;
    vector<int> ints({2, 3, 4, 2});
    vector<int> res = s.productExceptSelf(ints);
    for (auto c : res)
        cout << c << ",";
}
#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    int maxProfit(vector<int> &prices)
    {
        if (prices.size() == 0)
            return 0;
        int sellVal = prices[prices.size() - 1];
        int maxProfit = 0;
        for (int i = prices.size() - 1; i >= 0; i--)
        {
            if (maxProfit < sellVal - prices[i])
                maxProfit = sellVal - prices[i];
            if (sellVal < prices[i])
                sellVal = prices[i];
        }
        return maxProfit > 0 ? maxProfit : 0;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {7, 1, 5, 3, 6, 4};
    cout << s.maxProfit(nums) << endl;
}
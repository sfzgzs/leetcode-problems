#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        if (cost.size() == 2)
            return min(cost[0], cost[1]);
        int twoStepsAgo = cost[0];
        int lastStep = cost[1];
        for (int i = 2; i < cost.size(); i++)
        {
            int current = min(twoStepsAgo, lastStep) + cost[i];
            twoStepsAgo = lastStep;
            lastStep = current;
        }
        return min(twoStepsAgo, lastStep);
    }
};

int main()
{
    Solution s;
    vector<int> all = {73, 74, 75, 71, 69, 72, 76, 73};
    printvector(s.minCostClimbingStairs(all));
}
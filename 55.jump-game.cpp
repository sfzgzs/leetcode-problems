#include <stack>
#include <vector>
#include <iostream>
#include <queue>

using namespace std;
class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        if (nums.size() < 2)
            return true;
        int earliestrechable = nums.size() - 1;
        int nextReachable;
        while (true)
        {
            for (int i = earliestrechable - 1; i >= 0; i--)
            {
                if (i + nums[i] >= earliestrechable)
                {
                    if (i == 0)
                        return true;
                    nextReachable = i;
                }
            }
            if (nextReachable == earliestrechable)
                return false;
            earliestrechable = nextReachable;
        }
        return false;
    }
};

int main()
{
    Solution s;
    vector<int> all = {3, 2, 1, 0, 4};
    cout << s.canJump(all);
}
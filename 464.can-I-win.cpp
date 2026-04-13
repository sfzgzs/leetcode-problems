#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>

using namespace std;

class Solution
{
public:
    unordered_map<int, bool> dp;

    bool dfs(int used, int remaining, int n)
    {
        if (dp.count(used))
            return dp[used];

        for (int i = 1; i <= n; i++)
        {
            int mask = 1 << i;

            if (used & mask)
                continue;

            if (i >= remaining)
                return dp[used] = true;

            if (!dfs(used | mask, remaining - i, n))
                return dp[used] = true;
        }

        return dp[used] = false;
    }

    bool canIWin(int maxChoosableInteger, int desiredTotal)
    {
        int sum = maxChoosableInteger * (maxChoosableInteger + 1) / 2;

        if (sum < desiredTotal)
            return false;

        if (desiredTotal <= 0)
            return true;

        return dfs(0, desiredTotal, maxChoosableInteger);
    }
};
int main()
{
    Solution s;
    cout << s.canIWin(10, 11) << "\n";
}
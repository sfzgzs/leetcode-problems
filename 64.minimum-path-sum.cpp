#include <stack>
#include <vector>
#include <iostream>

using namespace std;
void printvector(const vector<int> &st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
class Solution
{
public:
    vector<vector<int>> dp;
    int minPathSum(vector<vector<int>> &grid)
    {
        if (grid.size() == grid[0].size() && grid.size() == 1)
            return grid[0][0];

        int rowCount = grid.size();
        int colCount = grid[0].size();

        vector<int> firstRow = grid[0];
        dp.push_back(firstRow);
        for (int i = 1; i < colCount; i++)
            dp[0][i] = dp[0][i - 1] + dp[0][i];

        for (int i = 1; i < rowCount; i++)
        {
            vector<int> tmp(colCount, -1);
            tmp[0] = grid[i][0] + dp[i - 1][0];
            dp.push_back(tmp);
        }
        for (int i = 1; i < rowCount; i++)
        {
            for (int j = 1; j < colCount; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[rowCount - 1][colCount - 1];
    }
};

int main()
{
    Solution s;
    vector<vector<int>> all = {{1, 2}, {5, 6}, {1, 1}};
    cout << s.minPathSum(all);
    cout << "-----------\n";

    for (int i = 0; i < s.dp.size(); i++)
        printvector(s.dp[i]);
}
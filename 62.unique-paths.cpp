#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{
public:
    int uniquePaths(int m, int n)
    {
        if (m == 1 || n == 1)
            return 1;
        vector<vector<int>> ways;
        vector<int> row1(n, 1);
        ways.push_back(row1);
        for (int row = 1; row < m; row++)
        {
            vector<int> wcol;
            wcol.push_back(1);
            for (int col = 1; col < n; col++)
            {
                wcol.push_back(wcol[col - 1] + ways[row - 1][col]);
            }
            ways.push_back(wcol);
        }
        return ways[m - 1][n - 1];
    }
};
int main()
{
    Solution s;
    cout << s.uniquePaths(3, 7);
}
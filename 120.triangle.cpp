#include <climits>
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

void printvector(const vector<int> &st, string str = "")
{
    if (str != "")
        cout << str << "\n";
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printmatrix(const vector<vector<int>> &triangle, int untilrow)
{
    cout << "printing \n";
    for (int i = 0; i <= untilrow; i++)
    {
        for (int j = 0; j < untilrow - i; j++)
            cout << " ";
        printvector(triangle[i]);
    }
}

class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int depth = triangle.size();
        if (depth == 1)
            return triangle[0][0];

        for (int row = 1; row < depth; row++) // this is the row number
        {
            // cout << "on the row " << row << endl;
            // current = 0 or size()-1: it should add up it's own weight to last row's
            triangle[row][0] += triangle[row - 1][0];
            triangle[row][row] += triangle[row - 1][row - 1];
            cout << "outside loop: row = " << row << ",set the first to  " << triangle[row][0] << " second to " << triangle[row][row] << " \n ";

            for (int current = 1; current < row; current++)
            {
                // cout << "inside loop: row = " << row << ", index = " << current << " current item = " << triangle[row][current] << ", min = " << min(triangle[row - 1][current - 1], triangle[row - 1][current]) << "\n ";
                triangle[row][current] += min(triangle[row - 1][current - 1], triangle[row - 1][current]);
            }
            // printmatrix(triangle, row);
        }
        int min = 10000000;
        for (int i = 0; i < depth; i++)
        {
            if (triangle[depth - 1][i] < min)
                min = triangle[depth - 1][i];
        }
        return min;
        return triangle[0][0];
    }
};
int main()
{
    Solution s;
    vector<vector<int>> ints = {{-1}, {-2, -3}};
    cout << s.minimumTotal(ints);
}

#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int squareIndex(int i, int j)
    {
        return (i / 3) * 3 + (j / 3);
    }
    bool isValidSudoku(vector<vector<char>> &board)
    {
        vector<unordered_set<char>> row(9, unordered_set<char>());
        vector<unordered_set<char>> col(9, unordered_set<char>());
        vector<unordered_set<char>> squares(9, unordered_set<char>());

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
            {
                if ((board[i])[j] != '.')
                {
                    int size = row[i].size();
                    row[i].insert((board[i])[j]);

                    if (size == row[i].size())
                        return false;
                    size = col[j].size();
                    col[j].insert((board[i])[j]);
                    if (size == col[j].size())
                        return false;
                    int sqNumber = squareIndex(i, j);
                    size = squares[sqNumber].size();
                    squares[sqNumber].insert((board[i])[j]);
                    if (size == squares[sqNumber].size())
                        return false;
                }
            }
        return true;
    }
};

int main()
{
    Solution s;
    vector<vector<char>> table =
        // {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        //  {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        //  {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        //  {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        //  {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        //  {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        //  {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        //  {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        //  {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        {{'1', '2', '.', '.', '3', '.', '.', '.', '.'},
         {'4', '.', '.', '5', '.', '.', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '.', '3'},
         {'5', '.', '.', '.', '6', '.', '.', '.', '4'},
         {'.', '.', '.', '8', '.', '3', '.', '.', '5'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '.', '.', '.', '.', '.', '2', '.', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '8'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    bool res = s.isValidSudoku(table);
    cout << res << endl;
}
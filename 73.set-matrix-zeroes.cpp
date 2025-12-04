#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void printvector(vector<int> st, string str = "")
{
    if (str != "")
        cout << str << "\n";
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}

class Solution
{
public:
    void setZeroes(vector<vector<int>> &matrix)
    {
        bool firstcolzero = 0;
        bool firstrowzero = 0;

        for (int i = 0; i < matrix.size(); i++)
            if (matrix[i][0] == 0)
            {
                firstcolzero = true;
                break;
            }

        for (int i = 0; i < matrix[0].size(); i++)
            if (matrix[0][i] == 0)
            {
                firstrowzero = true;
                break;
            }

        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == 0)
                {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }
        // for (int i = 0; i < matrix.size(); i++)
        //     printvector(matrix[i]);
        // cout << "\n ----------\n ";
        // zeroing rows
        for (int i = 1; i < matrix.size(); i++)
        {
            if (matrix[i][0] == 0)
                for (int j = 0; j < matrix[0].size(); j++)
                    matrix[i][j] = 0;
        }
        // cout << "\n zeroing rows\n ";

        // for (int i = 0; i < matrix.size(); i++)
        //     printvector(matrix[i]);
        // cout << "\n ----------\n ";
        // cout << "\n firstcol zero?" << firstcolzero << "\n ";

        // zeroing other columns
        for (int i = 1; i < matrix[0].size(); i++)
            if (matrix[0][i] == 0)
                for (int j = 0; j < matrix.size(); j++)
                    matrix[j][i] = 0;
        // zeroing column 0
        if (firstcolzero)
            for (int j = 0; j < matrix.size(); j++)
                matrix[j][0] = 0;
        // zeroing row 0
        if (firstrowzero)
            for (int j = 0; j < matrix[0].size(); j++)
                matrix[0][j] = 0;
    }
};

int main()
{
    Solution s;
    // vector<vector<int>> table = {{1}, {0}, {3}};
    vector<vector<int>> table = {{1, 2, 3, 4}, {5, 0, 7, 8}, {0, 10, 11, 12}, {13, 14, 15, 0}};
    cout << "\n input:\n";
    for (int i = 0; i < table.size(); i++)
        printvector(table[i]);

    s.setZeroes(table);
    cout << "\n output:\n";
    for (int i = 0; i < table.size(); i++)
        printvector(table[i]);
}
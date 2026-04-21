#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_map>
using namespace std;

void printvector(const vector<int> &st, string str = "")
{
    if (str != "")
        cout << str << "\n";
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printmatrix(const vector<vector<int>> &all)
{
    cout << "printing \n";
    for (int i = 0; i < all.size(); i++)
    {
        for (int j = 0; j < all.size(); j++)
            cout << " ";
        printvector(all[i], "");
    }
}
class Solution
{
public:
    string encode(const vector<int> &v)
    {
        string key;
        for (int x : v)
        {
            key += to_string(x) + "#"; // delimiter!
        }
        return key;
    }
    int equalPairs(vector<vector<int>> &grid)
    {
        int n = grid.size();
        if (n == 1)
            return 1;
        printmatrix(grid);
        vector<vector<int>> cols(n, vector<int>(n));

        for (int i = 0; i < n; i++)
        {
            transform(grid.begin(), grid.end(),
                      cols[i].begin(),
                      [i](const auto &v)
                      { return v[i]; });
        }
        printmatrix(cols);
        unordered_map<string, pair<int, int>> all;
        for (auto &v : grid)
        {
            all[encode(v)].first++;
        }
        for (auto &c : cols)
        {
            all[encode(c)].second++;
        }
        int sum = 0;
        for (auto &[key, p] : all)
        {
            sum += p.first * p.second;
        }
        return sum;
    }
};
int main()
{
    Solution s;
    vector<vector<int>> ints = {{3, 1, 2, 2}, {1, 4, 4, 5}, {2, 4, 2, 2}, {2, 4, 2, 2}};
    cout << s.equalPairs(ints);
}

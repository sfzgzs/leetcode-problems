#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    int maxSetSize = 0;
    int mGoal = 0;
    int nGoal = 0;
    int strsCount = 0;
    unordered_map<string, int> ones;
    unordered_map<string, int> zeroes;
    // NO DP
    void next(vector<string> &strs, int index, int mSoFar, int nSoFar, int countSoFar)
    {
        if (nSoFar > nGoal || mSoFar > mGoal)
        {
            maxSetSize = max(maxSetSize, countSoFar - 1);
            return;
        }
        if (index == strsCount)
        {
            maxSetSize = max(maxSetSize, countSoFar);
            return;
        }
        string current = strs[index];
        next(strs, index + 1, mSoFar + zeroes[current], nSoFar + ones[current], countSoFar + 1);
        next(strs, index + 1, mSoFar, nSoFar, countSoFar);
    }
    int findMaxForm(vector<string> &strs, int m, int n)
    {
        mGoal = m;
        nGoal = n;
        strsCount = strs.size();
        for (string s : strs)
        {
            ones.insert(make_pair(s, count(s.begin(), s.end(), '1')));
            zeroes.insert(make_pair(s, count(s.begin(), s.end(), '0')));
        }
        sort(strs.begin(), strs.end());
        next(strs, 0, 0, 0, 0);
        return maxSetSize;
    }
};

int main()
{
    Solution s;
    vector<string> strs = {"01", "0", "1", "1000", "111001"};
    cout << s.findMaxForm(strs, 5, 3) << "\n";
}
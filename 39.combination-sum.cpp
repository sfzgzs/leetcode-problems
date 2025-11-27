#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

class Solution
{
public:
    vector<vector<int>> results;
    void combHelper(vector<int> &candidates, int target, int index, vector<int> &res, int total)
    {
        if (total == target)
        {
            vector<int> newv(res.begin(), res.end());
            results.push_back(newv);
            return;
        }
        if (index >= candidates.size() || total > target)
        {
            return;
        }
        res.push_back(candidates[index]);
        combHelper(candidates, target, index, res, total + candidates[index]);
        res.pop_back();

        combHelper(candidates, target, index + 1, res, total);
    }
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        sort(candidates.begin(), candidates.end());
        vector<int> res;
        combHelper(candidates, target, 0, res, 0);
        return results;
    }
};

void printvector(vector<int> st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
int main()
{
    Solution s;
    vector<int> nums = {2, 3, 6, 7};
    auto res = s.combinationSum(nums, 7);
    for (auto v : res)
    {
        printvector(v);
        cout << endl;
    }
}

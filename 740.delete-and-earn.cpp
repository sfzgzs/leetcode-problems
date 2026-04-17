#include <climits>
#include <iostream>
#include <string>
#include <map>
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
class Solution
{
public:
    unordered_map<string, int> mem;

    string encode(map<int, int> &rep)
    {
        string s = "";
        for (auto &[k, v] : rep)
        {
            s += to_string(k) + "#" + to_string(v) + ",";
        }
        return s;
    }

    int earn_no_dp(map<int, int> &repitions)
    {
        if (repitions.empty())
            return 0;

        string key = encode(repitions);
        if (mem.count(key))
            return mem[key];

        int best = 0;

        vector<int> keys;
        for (auto &[k, _] : repitions)
            keys.push_back(k);

        for (int k : keys)
        {
            map<int, int> next = repitions;

            int gain = k * next[k];
            next.erase(k);

            if (next.count(k - 1))
                next.erase(k - 1);
            if (next.count(k + 1))
                next.erase(k + 1);

            best = max(best, gain + earn(next));
        }

        return mem[key] = best;
    }

    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> repitions;
        for (int num : nums)
            repitions[num]++;

        return earn_no_dp(nums);
    }
};
int main()
{
    Solution s;
    vector<int> inp = {2, 2, 3, 3, 3, 4};
    cout << s.deleteAndEarn(inp) << "\n";
}
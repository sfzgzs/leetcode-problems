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
    int earn_dp(map<int, int> &repitions)
    {
        vector<pair<int, int>> keyRepetitions(repitions.begin(), repitions.end());

        int keyRepetitionssize = keyRepetitions.size();
        vector<int> dp(keyRepetitionssize, 0);

        dp[0] = keyRepetitions[0].first * keyRepetitions[0].second; // how much we would gaing by picking 0th elem

        for (int i = 1; i < keyRepetitionssize; i++)
        {
            int gain = keyRepetitions[i].first * keyRepetitions[i].second; // gain by selecting elem i

            if (keyRepetitions[i].first == keyRepetitions[i - 1].first + 1) // in case (key = last key - 1) ignore it
            {
                int take = gain;
                if (i > 1) // also check the left side
                    take += dp[i - 2];

                dp[i] = max(dp[i - 1], take); // figure out if taking i-1 is better, or taking (i and i-2) together
            }
            else
            {
                dp[i] = dp[i - 1] + gain; // keys are not neighbors, so it's fine
            }
        }

        return dp[keyRepetitionssize - 1];
    }
    int deleteAndEarn(vector<int> &nums)
    {
        map<int, int> repitions;
        for (int num : nums)
            repitions[num]++;

        return earn_dp(repitions);
    }
};
int main()
{
    Solution s;
    vector<int> inp = {2, 2, 3, 3, 3, 4};
    cout << s.deleteAndEarn(inp) << "\n";
}
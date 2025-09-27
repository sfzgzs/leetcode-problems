#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> counts;

        for (int &num : nums)
        {
            counts[num]++;
        }
        vector<pair<int, int>> sorted(counts.begin(), counts.end());
        sort(sorted.begin(), sorted.end(), [](auto &a, auto &b)
             { return a.second > b.second; });

        vector<int> res;
        for (int i = 0; i < k; i++)
        {
            res.push_back(sorted[i].first);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> inp = {1, 1, 1, 1, 2, 2, 3, 4};
    cout << "Random shit:" << endl;
    vector<int> res = s.topKFrequent(inp, 2);
    cout << "topKFrequent " << res[0] << " and " << res[1] << endl;
}

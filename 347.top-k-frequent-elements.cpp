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

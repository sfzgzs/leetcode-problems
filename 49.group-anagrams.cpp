#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> all;
        for (string s : strs)
        {
            string tmpStr = s;
            sort(s.begin(), s.end(), [](char c1, char c2)
                 { return c1 < c2; });
            all[s].push_back(tmpStr);
        }

        vector<vector<string>> res;
        for (auto pair : all)
        {
            res.push_back(move(pair.second));
        }
        return res;
    }
};
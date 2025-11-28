#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    pair<char, int> maxPair(unordered_map<char, int> vec)
    {
        int max = 0;
        pair<char, int> maxPair;
        for (auto &rec : vec)
        {
            if (rec.second > max)
            {
                max = rec.second;
                maxPair = rec;
            }
        }
        return maxPair;
    }

    int characterReplacement(string s, int k)
    {
        unordered_map<char, int> seen;
        int l = 0;
        int maxCount = 1;

        for (int r = 0; r < s.size(); r++)
        {
            seen[s[r]]++;
            auto maxP = maxPair(seen);
            while ((r - l + 1) - maxP.second > k)
            {
                seen[s[l]]--;
                l++;
                maxP = maxPair(seen);
            }
            maxCount = max(maxCount, r - l + 1);
        }
        return maxCount;
    }
};
int main()
{
    Solution s;
    string chars = "AABABBA";
    auto res = s.characterReplacement(chars, 1);
    cout << "RESULT" << res << endl;
}

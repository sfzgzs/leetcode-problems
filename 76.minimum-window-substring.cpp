#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    int need = 0;
    int have = 0;
    int minResStartIndex = 0;
    int minResEndIndex = 0;
    string minWindow(string s, string t)
    {
        if (t == "" || t.size() > s.size())
            return "";
        string result = "";
        bool resultFound = false;
        unordered_map<char, int> tmap;
        for (char c : t)
            tmap[c]++;
        need = tmap.size();
        unordered_map<char, int> currmap;
        int startptr = 0;
        for (int endptr = 0; endptr < s.size(); endptr++)
        {
            char c = s[endptr];
            if (tmap.find(c) == tmap.end())
                continue;
            currmap[c]++;
            if (currmap[c] == tmap[c])
                have += 1;
            while (have == need)
            {
                if (!resultFound || endptr - startptr < minResEndIndex - minResStartIndex)
                {
                    minResEndIndex = endptr;
                    minResStartIndex = startptr;
                    resultFound = true;
                }
                char beginc = s[startptr];
                if (tmap.find(beginc) != tmap.end())
                {
                    currmap[beginc]--;
                    if (currmap[beginc] < tmap[beginc])
                        have--;
                }
                startptr++;
            }
        }
        if (resultFound)
            return s.substr(minResStartIndex, minResEndIndex - minResStartIndex + 1);
        ;
        return "";
    }
};
int main()
{
    Solution s;
    string str = "ADOBECODEBANC";
    string t = "ABC";
    auto res = s.minWindow(str, t);
}

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
            cout << "in for \n";
            char c = s[endptr];
            currmap[c]++;
            if (tmap.find(c) == tmap.end())
                continue;
            cout << "In loop, char=" << c << ", startptr=" << startptr << ", endptr=" << endptr << "\n";
            if (currmap[c] == tmap[c])
                have += 1;
            while (have == need)
            {
                // update result
                string currResult = s.substr(startptr, endptr - startptr + 1);
                cout << "in have == need current res" << currResult << "\n";
                if (!resultFound || currResult.size() < result.size())
                {
                    cout << "update result\n";
                    result = currResult;
                    resultFound = true;
                }
                // pop from left
                char beginc = s[startptr];
                if (tmap.find(beginc) != tmap.end())
                {
                    cout << "removing " << beginc << "\n";
                    currmap[beginc]--;
                }
                if (currmap[beginc] < tmap[beginc])
                    have--;
                startptr++;
            }
        }
        if (resultFound)
            return result;
        return "";
    }
};
int main()
{
    Solution s;
    string str = "ADOBECODEBANC";
    string t = "ABC";
    auto res = s.minWindow(str, t);
    cout << "RESULT" << res << "." << endl;
}

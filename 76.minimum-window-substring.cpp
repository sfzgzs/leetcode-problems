#include <iostream>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
class Solution
{
public:
    bool isRemovalFine(char c, unordered_map<char, int> &currmap, unordered_map<char, int> &tmap)
    {
        cout << "Testing is Removal: char " << c << " found?" << (tmap.find(c) == tmap.end()) << " orrr " << (tmap[c] < currmap[c]) << "\n";
        return (tmap.find(c) == tmap.end()) || (tmap[c] < currmap[c]);
    }
    bool matching(unordered_map<char, int> &currmap, unordered_map<char, int> &tmap)
    {
        for (auto pair : tmap)
        {
            if (currmap[pair.first] < pair.second)
            {
                cout << "looking for " << pair.first << " ... not found\n";
                return false;
            }
        }
        return true;
    }
    string minWindow(string s, string t)
    {
        string result = "";
        bool resultFound = false;

        unordered_map<char, int> tmap;
        for (char c : t)
            tmap[c]++;

        unordered_map<char, int> currmap;

        int startptr = 0;

        for (int endptr = 0; endptr < s.size(); endptr++)
        {
            char c = s[endptr];
            currmap[c]++;

            cout << "In loop, char=" << c << ", startptr=" << startptr << ", endptr=" << endptr << "\n";

            // If current window contains all needed chars, try shrinking
            while (matching(currmap, tmap) && isRemovalFine(s[startptr], currmap, tmap))
            {
                cout << "Shrinking: removing " << s[startptr] << "\n";
                currmap[s[startptr]]--;
                startptr++;
            }

            // After shrinking, if window is valid → update result
            if (matching(currmap, tmap))
            {
                string currResult = s.substr(startptr, endptr - startptr + 1);
                if (!resultFound || currResult.size() < result.size())
                {
                    result = currResult;
                    resultFound = true;
                }
            }
        }

        return result;
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

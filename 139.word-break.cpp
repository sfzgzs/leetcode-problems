
#include <string>
#include <iostream>
#include <stack>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <map>

using namespace std;

class Solution
{
public:
    string mainstr;
    unordered_map<char, vector<string>> wordsStartingWith;
    map<int, bool> reachable;

    void match(int startindex)
    {
        auto &suspects = wordsStartingWith[mainstr[startindex]];
        for (string matchingword : suspects)
        {
            if (startindex + matchingword.size() <= mainstr.size())
                if (matchingword == mainstr.substr(startindex, matchingword.size()))
                {
                    reachable[startindex + matchingword.size()] = true;
                    cout << "I added index " << startindex + matchingword.size() - 1 << "with word " << matchingword << endl;
                }
        }
    }
    bool wordBreak(string s, vector<string> &wordDict)
    {
        mainstr = s;
        for (string w : wordDict)
        {
            wordsStartingWith[w[0]].push_back(w);
        }
        for (auto &[ch, wlist] : wordsStartingWith)
        {
            sort(wlist.begin(), wlist.end(), greater<string>());
        }
        reachable[0] = true;
        int currentindex = 0;
        while (!reachable.empty())
        {
            auto &[indx, reach] = *reachable.begin();
            currentindex = indx;
            if (currentindex == s.size())
                return true;
            cout << "current index being " << currentindex << endl;
            match(currentindex);
            reachable.erase(currentindex);
        }
        return false;
    }
};
int main()
{
    string s = "catsandog";
    vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
    Solution sol;
    cout << sol.wordBreak(s, wordDict);
}
#include <string>
#include <unordered_set>
#include <iostream>
#include <set>
#include <unordered_map>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
public:
    bool closeStrings(string word1, string word2)
    {
        // check size
        if (word1.size() != word2.size())
            return false;
        // check all letters
        set<char> w1set(word1.begin(), word1.end());
        set<char> w2set(word2.begin(), word2.end());
        if (w1set != w2set)
            return false;
        unordered_map<char, int> map1;
        for (char c : word1)
            map1[c]++;
        unordered_map<char, int> map2;
        for (char c : word2)
            map2[c]++;
        vector<int> s1;
        std::transform(map1.begin(), map1.end(),
                       std::inserter(s1, s1.begin()),
                       [](const auto &pair)
                       { return pair.second; });
        vector<int> s2;
        std::transform(map2.begin(), map2.end(),
                       std::inserter(s2, s2.begin()),
                       [](const auto &pair)
                       { return pair.second; });
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        return s1 == s2;
    }
};

int main()
{
    string str1 = "aaabbbbccddeeeeefffff";
    string str2 = "aaaaabbcccdddeeeeffff";
    Solution s;
    cout << s.closeStrings(str1, str2);
}
#include <string>
#include <iostream>
#include <unordered_map>

using namespace std;

void printMap(unordered_map<char, int> m)
{
    for (auto &pair : m)
        cout << pair.first << ": " << pair.second << endl;
}

class Solution
{
public:
    // Not Necessarily Contiguous
    // bool checkInclusion(string s1, string s2)
    // {
    //     multiset<char> s2chars(s2.begin(), s2.end());
    //     cout << "s2\n";
    //     for (auto it = s2chars.begin(); it != s2chars.end(); ++it)
    //         std::cout << ' ' << *it;
    //     cout << endl;
    //     for (char c1 : s1)
    //     {
    //         std::cout << c1 << ' ';
    //         auto it = s2chars.find(c1);
    //         if (it == s2chars.end())
    //             return false;
    //         s2chars.erase(it);
    //         cout << "\nnow erased\n";
    //         cout << "s2\n";
    //         for (it = s2chars.begin(); it != s2chars.end(); ++it)
    //             std::cout << ' ' << *it;
    //         cout << endl;
    //     }
    //     return true;
    // }

    // Contiguous:
    // is one of s1's permutations a substring of s2.
    bool checkInclusion(string s1, string s2)
    {
        cout << "tf??? \n";

        unordered_map<char, int> need;
        unordered_map<char, int> have;
        if (s2.size() < s1.size())
            return false;
        for (char c : s1)
            need[c]++;
        int r = 0;
        for (int l = 0; l < s2.size(); l++)
        {
            char c = s2[l];
            if (need.count(c) == 0)
                continue;
            r = l;
            while (l <= r && r < s2.size())
            {
                if (need.count(s2.at(r)) == 0)
                {
                    have.clear();
                    break;
                }
                have[s2[r]]++;
                while (have[s2[r]] > need[s2[r]])
                {
                    have[s2[l]]--;
                    l++;
                }

                if (have == need)
                    return true;
                r++;
            }
            have.clear();
        }
        return false;
    }
};
int main()
{
    Solution s;
    string st1 = "hello";
    string st2 = "ooolleoooleh";
    cout << s.checkInclusion(st1, st2);
}
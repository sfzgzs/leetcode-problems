#include <string>
#include <iostream>
#include <set>

using namespace std;

class Solution
{
public:
    bool checkInclusion(string s1, string s2)
    {
        multiset<char> s2chars(s2.begin(), s2.end());
        cout << "s2\n";
        for (auto it = s2chars.begin(); it != s2chars.end(); ++it)
            std::cout << ' ' << *it;
        cout << endl;
        for (char c1 : s1)
        {
            std::cout << c1 << ' ';
            auto it = s2chars.find(c1);
            if (it == s2chars.end())
                return false;
            s2chars.erase(it);
            cout << "\nnow erased\n";
            cout << "s2\n";
            for (it = s2chars.begin(); it != s2chars.end(); ++it)
                std::cout << ' ' << *it;
            cout << endl;
        }
        return true;
    }
};
int main()
{
    Solution s;
    string st1 = "abc";
    string st2 = "lecaabee";
    cout << s.checkInclusion(st1, st2);
}
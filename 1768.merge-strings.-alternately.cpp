#include <iostream>
#include <algorithm>
#include <string>

using namespace std;
class Solution
{
public:
    string mergeAlternately(string word1, string word2)
    {
        int m = min(word1.size(), word2.size());
        string res = "";
        for (int i = 0; i < m; i++)
        {
            string tmp = "";
            tmp += word1[i];
            tmp += word2[i];
            res += tmp;
        }
        if (m < word1.size())
        {
            res += (word1.substr(m));
        }
        else if (m < word2.size())
        {
            res += (word2.substr(m));
        }
        return res;
    }
};

int main()
{
    string a1 = "abc";
    string a2 = "pqr";
    Solution s;
    cout << s.mergeAlternately(a1, a2);
}
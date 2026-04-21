#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>
#include <climits>

using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        vector<string> words;
        int index = 0;
        while (index < s.size() && s[index] == ' ')
            index++;

        string w = "";
        while (index < s.size())
        {
            w = "";
            while (index < s.size() && s[index] != ' ')
            {
                w += s[index];
                index++;
            }
            words.push_back(w);
            while (index < s.size() && s[index] == ' ')
            {
                index++;
            }
        }
        string s2 = "";
        for (int i = 0; i < words.size(); i++)
            s2 = " " + words[i] + s2;
        return s2.substr(1);
    }
};
int main()
{
    Solution s;
    string st = "hello  beau tifool! world!!! ";
    cout << s.reverseWords(st);
}
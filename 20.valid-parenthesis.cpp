#include <string>
#include <iostream>
#include <stack>

using namespace std;

class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> stc;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
                stc.push(c);
            else
            {
                if (stc.empty())
                    return false;
                if (c == ')')
                {
                    if (stc.top() != '(')
                        return false;
                }
                else if (c == '}')
                {
                    if (stc.top() != '{')
                        return false;
                }
                else if (c == ']')
                {
                    if (stc.top() != '[')
                        return false;
                }

                stc.pop();
            }
        }
        return stc.empty();
    }
};
int main()
{
    Solution s;
    // string st = "([{}])";
    string st = "()[]}";
    // string st = "(()()())())";
    cout << s.isValid(st);
}
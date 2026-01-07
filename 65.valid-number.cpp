#include <iostream>
#include <string>

using namespace std;

class Solution
{
public:
    bool isdigit(char c)
    {
        // bool res = (c >= '0') && (c <= '9');
        return (c >= '0') && (c <= '9');
    }
    bool isNumber(string s)
    {
        int state = 0;
        for (char c : s)
        {
            if (state == 0)
            {
                if (c == '-' || c == '+')
                {
                    state = 1;
                    continue;
                }
                else if (isdigit(c))
                {
                    state = 2;
                    continue;
                }
                else if (c == '.')
                {
                    state = 8;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 1)
            {
                if (isdigit(c))
                {
                    state = 2;
                    continue;
                }
                else if (c == '.')
                {
                    state = 8;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 2)
            {
                if (isdigit(c))
                {
                    continue;
                }
                else if (c == '.')
                {
                    state = 3;
                    continue;
                }
                else if (c == 'E' || c == 'e')
                {
                    state = 5;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 3)
            {
                if (isdigit(c))
                {
                    continue;
                }
                else if (c == 'E' || c == 'e')
                {
                    state = 5;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 5)
            {
                if (c == '-' || c == '+')
                {
                    state = 6;
                    continue;
                }
                else if (isdigit(c))
                {
                    state = 7;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 6)
            {
                if (isdigit(c))
                {
                    state = 7;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 7)
            {
                if (isdigit(c))
                {
                    state = 7;
                    continue;
                }
                else
                    return false;
            }
            else if (state == 8)
            {
                if (isdigit(c))
                {
                    state = 3;
                    continue;
                }
                else
                    return false;
            }
        }
        if (state == 2 || state == 3 || state == 7)
        {
            return true;
        }
        else
            return false;
    }
};
int main()
{
    string s = "+.8";
    Solution sol;
    cout << sol.isNumber(s);
}
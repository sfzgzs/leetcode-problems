#include <iostream>
#include <queue>
#include <string>

using namespace std;
class Solution
{
public:
    int lengthOfLastWord(string s)
    {
        int lastindex = -1;

        int i = s.size() - 1;
        while (i >= 0 && s[i] == ' ')
        {
            i--;
        }
        if (i == -1)
            return 0;
        lastindex = i;

        while (i >= 0 && s[i] != ' ')
        {
            i--;
        }

        return lastindex - i;
    }
};
int main(int argc, char const *argv[])
{
    string str = "a";
    Solution s;
    cout << s.lengthOfLastWord(str);
    return 0;
}

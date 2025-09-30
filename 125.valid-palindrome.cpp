#include <string>
#include <iostream>
#include <vector>
#include <cctype>

using namespace std;
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int i = 0, j = s.size() - 1;
        while (true)
        {
            cout << "i is " << i << " and j is" << j << endl;
            while (!isalnum(s[i]))
                i++;
            while (!isalnum(s[j]))
                j--;
            if (i > j)
                return true;
            if (tolower(s[i]) != tolower(s[j]))
                return false;
            i++;
            j--;
        }
        return true;
    }
};
int main()
{
    Solution s;
    cout << s.isPalindrome("Madam, in Eden, I'm Adam") << ",";
}
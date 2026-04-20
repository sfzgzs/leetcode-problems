#include <string>
#include <iostream>
#include <string>
#include <numeric>
using namespace std;
class Solution
{
public:
    string mult(string base, int count)
    {
        string res = "";
        for (int i = 0; i < count; i++)
            res += base;
        // cout << "resss " << res << endl;
        return res;
    }
    string gcdOfStrings(string str1, string str2)
    {
        int gcdsize = gcd(str1.size(), str2.size());
        // cout << "GDC " << gcdsize;
        for (int len = gcdsize; len >= 1; len--)
        {
            string unit = str1.substr(0, len);
            // cout << "unit " << unit << "count " << str1.size() / gcdsize << endl;

            if (mult(unit, str1.size() / gcdsize) == str1 && mult(unit, str2.size() / gcdsize) == str2)
                return unit;
        }
        return "";
    }
};
int main()
{
    string s1 = "ABCABC";
    string s2 = "ABC";
    Solution s;
    cout << s.gcdOfStrings(s1, s2) << endl;
}
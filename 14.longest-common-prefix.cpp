#include <iostream>
#include <vector>
#include <string>

using namespace std;
class Solution
{
public:
    string longestCommonPrefix(vector<string> &strs)
    {
        int index = 0;
        while (true)
        {
            for (int i = 0; i < strs.size(); i++)
            {
                if (strs[i].size() <= index || strs[i][index] != strs[0][index])
                {
                    return strs[0].substr(0, index);
                }
            }
            index++;
        }
    }
};
int main()
{
    string str1 = "flower";
    string str2 = "flow";
    string str3 = "flight";

    vector<string> all = {str1, str2, str3};
    // vector<string> all = {"dog", "racecar", "car"};
    Solution s;
    cout << s.longestCommonPrefix(all);
    cout << "eh?";
}
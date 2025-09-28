#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    string delimiter = ";";
    string encode(vector<string> &strs)
    {
        string res = "";
        for (string s : strs)
        {
            res += to_string(s.size());
            res += ";";
            res += s;
        }
        return res;
    }

    vector<string> decode(string s)
    {
        vector<string> res;
        int index = 0;
        while (index < s.size())
        {
            string word = "";
            while (s.at(index) != delimiter[0])
            {
                word += s[index];
                index++;
            }
            int wordLen = stoi(word);
            string w = "";
            index++;

            for (int i = 0; i < wordLen; i++)
            {
                w += s[index + i];
            }
            index += wordLen;
            res.push_back(w);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<string> strs({"asdf", "1234", "123456sdfg", ""});
    string code = s.encode(strs);
    cout << code << endl;
    auto res = s.decode(code);
    for (auto c : res)
        cout << c << ",";
}
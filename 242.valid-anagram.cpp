#include <string>
#include <unordered_map>

using namespace std;

void printMap(unordered_map<char, int> m)
{
    for (auto &pair : m)
        cout << pair.first << ": " << pair.second << endl;
}

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        unordered_map<char, int> schars;
        unordered_map<char, int> tchars;
        int size = s.size();
        if (size != t.size())
            return false;
        for (int i = 0; i < size; i++)
        {
            schars[s[i]]++;
            tchars[t[i]]++;
        }
        return schars == tchars;
    }
};

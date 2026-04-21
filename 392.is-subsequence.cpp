#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

#include <iostream>
#include <unordered_map>
#include <string>
#include <queue>
using namespace std;

class Solution
{
public:
    bool isSubsequence_map(string s, string t)
    {
        unordered_map<char, queue<int>> indices; // a map of char to indices
        for (int i = 0; i < t.size(); i++)
            indices[t[i]].push(i);

        int lastindex = -1; // last index to have found
        for (int i = 0; i < s.size(); i++)
        {
            char c = s[i]; // current char to find in indices
            if (indices.find(c) == indices.end())
                return false; // if there is no more of c, definietely not a subseq
            bool found = false;
            int size = indices[c].size();
            for (int j = 0; j < size; j++) // go through all indices of that char
            {
                if (indices[c].front() <= lastindex) // pop the not-useful ones
                    indices[c].pop();
                else
                {
                    found = true;
                    lastindex = indices[c].front();
                    indices[c].pop();
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
    bool isSubsequence_two_pointers(string s, string t)
    {
        if (s.size() > t.size())
            return false;
        if (s.size() == 0)
            return true;
        int pt = 0;
        for (int is = 0; is < s.size(); is++)
        {
            bool found = false;
            for (int it = pt; it < t.size(); it++)
            {
                if (t[it] == s[is])
                {
                    found = true;
                    pt = it;
                    break;
                }
            }
            if (!found)
                return false;
        }
        return true;
    }
};

int main()
{
    Solution s;
    string s1 = "acb";
    string s2 = "ahbgdc";
    auto res = s.isSubsequence_two_pointers(s1, s2);
    cout << res << endl;
}
#include <algorithm>
#include <string>
#include <iostream>
#include <unordered_set>
#include <vector>
#include <numeric>
using namespace std;

void printvector(const vector<bool> &v)
{
    for (bool b : v)
        cout << b << " ";
    cout << endl;
}
class Solution
{
public:
    int maxVowels(string s, int k)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
        vector<bool> isVowel;
        transform(s.begin(), s.end(), inserter(isVowel, isVowel.begin()), [=](auto &c)
                  { return vowels.count(c); });
        // printvector(isVowel);
        if (k > s.length())
            return accumulate(isVowel.begin(), isVowel.end(), 0, [](int sum, bool b)
                              { return sum += b ? 1 : 0; });
        int maxsum = accumulate(isVowel.begin(), isVowel.begin() + k, 0, [](int sum, bool b)
                                { return sum += (b ? 1 : 0); });
        // cout << " sum is " << sum << endl;
        int currentsum = maxsum;
        for (int i = 0; i + k < s.size(); i++)
        {
            if (isVowel[i])
                currentsum--;
            if (isVowel[i + k])
                currentsum++;
            maxsum = max(maxsum, currentsum);
        }
        return maxsum;
    }
};
int main()
{
    Solution s;
    cout << s.maxVowels("asdgert", 2) << endl;
    cout << s.maxVowels("asdgert", 3) << endl;
    cout << s.maxVowels("asdgert", 4) << endl;
    cout << s.maxVowels("asdgert", 5) << endl;
    cout << s.maxVowels("asdgert", 6) << endl;
}
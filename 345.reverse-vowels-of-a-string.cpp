#include <string>
#include <unordered_set>
#include <iostream>

using namespace std;

class Solution
{
public:
    string reverseVowels(string s)
    {
        unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        int leftptr = 0;
        int rightptr = s.size() - 1;

        while (leftptr < rightptr)
        {
            while (leftptr < rightptr && vowels.find(s[leftptr]) == vowels.end())
                leftptr++;

            while (leftptr < rightptr && vowels.find(s[rightptr]) == vowels.end())
                rightptr--;

            if (leftptr < rightptr)
            {
                swap(s[leftptr], s[rightptr]);
                leftptr++;
                rightptr--;
            }
        }

        return s;
    }
};

int main()
{
    string str = "IceCreAm";
    Solution s;
    cout << s.reverseVowels(str);
}
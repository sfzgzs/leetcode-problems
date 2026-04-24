#include <string>
#include <stack>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    string decodeString(string s)
    {
        stack<string> stringstack;
        stack<int> numberstack;
        string currentNum = "";

        for (char current : s)
        {
            if (isdigit(current))
            { // might have multiple digits
                currentNum += current;
            }
            else if (current == '[')
            { // done with the number, push it
                numberstack.push(stoi(currentNum));
                currentNum = ""; // Reset number
                stringstack.push("[");
            }
            else if (current == ']')
            {
                // pop everything between brackets
                string subContent = "";
                while (stringstack.top() != "[")
                {
                    subContent = stringstack.top() + subContent;
                    stringstack.pop();
                }
                stringstack.pop();

                int multcount = numberstack.top();
                numberstack.pop();

                string repeatedString = "";
                for (int i = 0; i < multcount; i++)
                {
                    repeatedString += subContent;
                }
                stringstack.push(repeatedString);
            }
            else
            {
                stringstack.push(string(1, current));
            }
        }

        string result = "";
        while (!stringstack.empty())
        {
            result = stringstack.top() + result;
            stringstack.pop();
        }
        return result;
    }
};
int main()
{
    string str = "3[a]2[bc]";
    Solution s;
    cout << s.decodeString(str);
}
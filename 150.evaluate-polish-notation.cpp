#include <stack>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void printstack(stack<string> st)
    {
        stack<string> tempStack = st;

        while (!tempStack.empty())
        {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }
    int eval(stack<string> &st)
    {
        string t = st.top();
        st.pop();
        if (t == "+")
            return eval(st) + eval(st);
        else if (t == "-")
        {
            int right = eval(st);
            int left = eval(st);
            return left - right;
        }
        else if (t == "*")
            return eval(st) * eval(st);
        else if (t == "/")
        {
            int right = eval(st);
            int left = eval(st);
            return left / right;
        }
        else
            return stoi(t);
    }
    int evalRPN(vector<string> &tokens)
    {
        stack<string> toks;
        for (auto t : tokens)
            toks.push(t);
        return eval(toks);
    }
};
int main()
{
    Solution s;
    vector<string> all = {"2", "3", "+", "4", "*"};
    cout << s.evalRPN(all);
}
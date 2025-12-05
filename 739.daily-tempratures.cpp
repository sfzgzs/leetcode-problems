#include <stack>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
public:
    void printstack(stack<int> st)
    {
        stack<int> tempStack = st;

        while (!tempStack.empty())
        {
            cout << tempStack.top() << " ";
            tempStack.pop();
        }
        cout << endl;
    }

    vector<int> dailyTemperatures(vector<int> &temperatures)
    {
        stack<pair<int, int>> stc;
        vector<int> res(temperatures.size(), 0);

        for (int tIndex = 0; tIndex < temperatures.size(); tIndex++)
        {
            while (!stc.empty() && temperatures[tIndex] > stc.top().first)
            {
                pair<int, int> topElem = stc.top();
                stc.pop();
                res[topElem.second] = tIndex - topElem.second;
            }
            stc.push(pair<int, int>(temperatures[tIndex], tIndex));
        }

        return res;
    }
};
void printvector(const vector<int> &st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<int> all = {73, 74, 75, 71, 69, 72, 76, 73};
    printvector(s.dailyTemperatures(all));
}
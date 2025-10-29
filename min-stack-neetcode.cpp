#include <climits>
#include <stack>
#include <iostream>
using namespace std;

class MinStack
{
private:
    stack<pair<int, int>> st;

public:
    MinStack() {}

    void push(int val)
    {
        if (st.empty())
        {
            st.push({val, val});
        }
        else
        {
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }

    void pop()
    {
        if (!st.empty())
            st.pop();
    }

    int top()
    {
        return st.top().first;
    }

    int getMin()
    {
        return st.top().second;
    }
};

int main()
{
    MinStack s;
    s.push(-2);
    s.push(0);
    s.push(-3);
    cout << s.getMin() << endl;
    s.pop();
    cout << s.top() << endl;
    cout << s.getMin() << endl;
}

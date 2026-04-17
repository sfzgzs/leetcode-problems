#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void printstack(stack<pair<int, int>> st)
{
    stack<pair<int, int>> tempStack;
    stack<pair<int, int>> tempStack2;
    while (!st.empty())
    {
        tempStack2.push(st.top());
        st.pop();
    }
    while (!tempStack2.empty())
    {
        st.push(tempStack2.top());
        tempStack.push(tempStack2.top());
        tempStack2.pop();
    }

    while (!tempStack.empty())
    {
        cout << "(" << tempStack.top().first << ", " << tempStack.top().second << "), ";
        tempStack.pop();
    }
    cout << endl;
}
class StockSpanner
{
public:
    stack<pair<int, int>> stocks; // keeps number, and the span returned

    StockSpanner()
    {
    }

    int next(int price)
    {
        int counter = 1;
        printstack(stocks);
        while (!stocks.empty() && stocks.top().first <= price)
        {
            cout << "popping " << stocks.top().first << ", " << stocks.top().second << endl;
            counter += stocks.top().second;
            stocks.pop();
        }

        cout << "pushing " << price << ", " << counter << endl;

        stocks.push({price, counter});
        cout << "--------------------\n";
        return counter;
    }
};
int main()
{
    StockSpanner s;
    s.next(100);
    s.next(80);
    s.next(60);
    s.next(70);
    s.next(60);
    s.next(75);
    s.next(85);
    return 0;
}
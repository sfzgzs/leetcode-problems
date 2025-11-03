#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution
{
public:
    void printVec(priority_queue<int> m)
    {
        while (!m.empty())
        {
            cout << m.top() << " ";
            m.pop();
        }
        cout << endl;
    }
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> st(stones.begin(), stones.end());
        printVec(st);
        while (st.size() > 1)
        {
            int s1 = st.top();
            st.pop();
            int s2 = st.top();
            st.pop();
            if (s1 != s2)
                st.push(abs(s1 - s2));
        }
        if (st.size() == 0)
            return 0;
        else
            return st.top();
    }
};
int main()
{
    Solution s;
    vector<int> ints = {2, 7, 4, 1, 8, 1};
    cout << s.lastStoneWeight(ints);
}

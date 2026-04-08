#include <stack>
#include <vector>
#include <iostream>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;
void printvector(const vector<bool> &st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printdp(unordered_map<int, unordered_map<int, bool>> &dp, vector<int> &stones)
{
    for (const auto &[index, jumpmap] : dp)
    {
        for (const auto &[jumpnumber, res] : jumpmap)
        {
            if (res)
                cout << " index[" << index << "] ..... " << stones[index] << " has a way to get with " << jumpnumber << " jumps! \n";
        }
    }

    cout << endl;
}
class Solution
{
public:
    bool canCross(vector<int> &stones)
    {
        if (stones[1] != 1)
            return false;
        unordered_map<int, unordered_set<int>> path;
        path[1].insert(1);
        for (int i = 1; i < stones.size(); i++)
        {
            for (int m = i - 1; m >= 1; m--) // look at stones before you
            {
                int dist = stones[i] - stones[m];

                if (dist > stones.size())
                    break;

                if ((path[m].count(dist - 1)) ||
                    (path[m].count(dist)) ||
                    (path[m].count(dist + 1)))
                    path[i].insert(dist);
            }
        }
        if (path[stones.size() - 1].empty())
            return false;
        else
            return true;
    }
};

int main()
{
    Solution s;
    vector<int> all = {0, 1, 3, 5, 6, 8, 12, 17};
    cout << s.canCross(all) << "\n";
}
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution
{
public:
    int eraseOverlapIntervals(vector<vector<int>> &intervals)
    {
        if (intervals.size() == 1)
            return 0;
        sort(intervals.begin(), intervals.end(), [](vector<int> &a1, vector<int> &a2)
             { return a1[0] < a2[0] || (a1[0] == a2[0] && a1[1] < a2[1]); });
        int lastInervalStart = intervals[0][0];
        int lastInervalEnd = intervals[0][1];
        int counter = 0;
        int index = 1;
        while (index < intervals.size())
        {
            if (intervals[index][0] == lastInervalStart) // means both start at the same and we remove the second
            {
                counter++;
                index++;
                continue;
            }
            if (intervals[index][1] < lastInervalEnd) // means they have nonempty intersection and interval i is kept
            {
                lastInervalStart = intervals[index][0];
                lastInervalEnd = intervals[index][1];
                counter++;
                index++;
                continue;
            }
            if (intervals[index][0] < lastInervalEnd)
            {
                counter++;
                index++;
                continue;
            }
            if (lastInervalEnd <= intervals[index][0])
            {
                lastInervalStart = intervals[index][0];
                lastInervalEnd = intervals[index][1];
                index++;
                continue;
            }
        }
        return counter;
    }
};

int main()
{
    vector<int> vect1 = {0, 2};
    vector<int> vect2 = {1, 3};
    vector<int> vect3 = {2, 4};
    vector<int> vect4 = {3, 5};
    vector<int> vect5 = {4, 6};
    vector<vector<int>> all;
    all.push_back(vect1);
    all.push_back(vect2);
    all.push_back(vect3);
    all.push_back(vect4);
    all.push_back(vect5);
    Solution s;
    cout << s.eraseOverlapIntervals(all);
}
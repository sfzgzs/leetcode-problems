#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Interval
{
public:
    int start;
    int end;
    Interval(int s, int f)
    {
        start = s;
        end = f;
    }
};
class Solution
{
public:
    bool canAttendMeetings(vector<Interval> &intervals)
    {
        if (intervals.size() <= 1)
            return true;

        sort(intervals.begin(), intervals.end(),
             [](const Interval &a, const Interval &b)
             {
                 return a.start < b.start;
             });

        for (int i = 1; i < intervals.size(); i++)
        {
            // if current start < previous end → overlap
            if (intervals[i].start < intervals[i - 1].end)
                return false;
        }

        return true;
    }
};

void printvector(vector<int> st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}

int main()
{
    Solution s;
    vector<Interval> meetings = {Interval(8, 11),
                                 Interval(10, 13),
                                 Interval(20, 22)};
    cout << s.canAttendMeetings(meetings);
}
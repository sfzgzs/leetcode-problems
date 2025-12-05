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
void printvector(const vector<int> &st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printwhatsleftof(vector<int> &st, int index)
{
    for (int i = index; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
class Solution
{
public:
    int minMeetingRooms(vector<Interval> &intervals)
    {
        vector<int> starts(intervals.size());
        vector<int> ends(intervals.size());

        transform(intervals.begin(), intervals.end(), starts.begin(), [](const Interval &intrv)
                  { return intrv.start; });
        transform(intervals.begin(), intervals.end(), ends.begin(), [](const Interval &intrv)
                  { return intrv.end; });
        sort(starts.begin(), starts.end());
        sort(ends.begin(), ends.end());
        // printvector(starts);
        // printvector(ends);
        int startsptr = 0;
        int endptr = 0;
        int count = 0;
        int maxcount = 0;
        for (int i = 0; i < intervals.size(); i++)
        {
            cout << "start= " << starts[startsptr];
            cout << ", end= " << ends[endptr] << endl;

            if (starts[startsptr] < ends[endptr])
            {
                startsptr++;
                count++;
            }
            else
            {
                endptr++;
                count--;
            }
            maxcount = max(maxcount, count);
        }
        return maxcount;
    }
};

int main()
{
    Solution s;
    vector<Interval> meetings = {{0, 10}, {10, 20}, {20, 30}, {30, 40}, {40, 50}, {50, 60}, {60, 70}, {70, 80}, {80, 90}, {90, 100}, {0, 100}, {10, 90}, {20, 80}, {30, 70}, {40, 60}};
    cout << s.minMeetingRooms(meetings);
}
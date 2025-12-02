#include <iostream>
#include <vector>
#include <deque>

using namespace std;

void printvector(vector<int> st, string str = "")
{
    if (str != "")
        cout << str << "\n";
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printdeque(deque<int> st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
class Solution
{
public:
    vector<int> maxSlidingWindow(vector<int> &nums, int k)
    {
        if (k == 1)
            return nums;
        vector<int> res;
        deque<int> maxs = {0};
        for (int i = 1; i < k; i++)
        {
            while (!maxs.empty() && nums[i] > nums[maxs.back()])
            {
                maxs.pop_back();
            }
            maxs.push_back(i);
            printvector(maxs);
        }
        res.push_back(nums[maxs.front()]);
        for (int i = k; i < nums.size(); i++)
        {
            if (!maxs.empty() && maxs.front() <= i - k)
                maxs.pop_front();
            while (!maxs.empty() && nums[i] > nums[maxs.back()])
                maxs.pop_back();

            maxs.push_back(i);
            res.push_back(nums[maxs.front()]);
        }
        return res;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    printvector(s.maxSlidingWindow(nums, 3), "output:");
}
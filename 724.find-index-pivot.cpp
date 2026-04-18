#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printvector(const vector<int> &st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        if (nums.size() == 1)
            return 0;
        int lastindex = nums.size() - 1;
        vector<int> leftsofar = {0};
        vector<int> rightsofar = {0};

        for (int i = 1; i <= lastindex; i++)
        {
            leftsofar.push_back(nums[i - 1] + leftsofar[i - 1]);
            rightsofar.insert(rightsofar.begin(), nums[lastindex - i + 1] + rightsofar[0]);
        }
        for (int i = 0; i <= lastindex; i++)
            if (leftsofar[i] == rightsofar[i])
                return i;
        return -1;
    }
};
int main()
{
    vector<int> all = {2, 1, -1};
    Solution s;
    cout << s.pivotIndex(all);
    return 0;
}
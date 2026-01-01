#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        if (nums.empty())
            return 0;
        int i = 1;
        int fast = 1;

        while (fast < nums.size())
        {
            if (nums[fast - 1] != nums[fast])
            {
                nums[i] = nums[fast];
                i++;
            }
            fast++;
        }
        return i;
    }
};
int main()
{
    vector<int> all = {1, 1, 2};
    Solution s;
    cout << s.removeDuplicates(all);
}
#include <iostream>
#include <vector>

// Used Floyd's alg
using namespace std;

class Solution
{
public:
    int findDuplicate(vector<int> &nums)
    {
        int slow = 0, fast = 0;
        do
        {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while (slow != fast);

        int slow2 = 0;
        do
        {
            slow = nums[slow];
            slow2 = nums[slow2];
        } while (slow != slow2);
        return slow;
    }
};
int main()
{
    Solution s;
    vector<int> nums = {1, 2, 3, 2, 2};
    auto res = s.findDuplicate(nums);
    cout << "RESULT" << res << endl;
}

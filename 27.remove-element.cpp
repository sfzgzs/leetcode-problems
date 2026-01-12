class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int fast = 0;
        int head = 0;
        while (fast < nums.size())
        {
            if (nums[fast] != val)
            {
                nums[head] = nums[fast];
                head++;
                fast++;
            }
            else
                fast++;
        }
        return head;
    }
};
#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int i = 0, j = numbers.size() - 1;
        while (i < j)
        {
            if (numbers[i] + numbers[j] > target)
                j--;
            else if (numbers[i] + numbers[j] < target)
                i++;
            else
                return vector<int>({i + 1, j + 1});
        }
        return vector<int>();
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 7, 11, 15};
    cout << s.twoSum(nums, 9)[0] << " " << s.twoSum(nums, 9)[1] << endl;
}
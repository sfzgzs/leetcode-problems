#include <vector>
#include <iostream>
#include <unordered_set>

class Solution
{
public:
    vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> justInNum1(nums1.begin(), nums1.end());
        unordered_set<int> justInNum2(nums2.begin(), nums2.end());
        for (int &n1 : nums1)
        {
            if (justInNum2.count(n1))
            {
                justInNum1.erase(n1);
                justInNum2.erase(n1);
            }
        }
        return (vector<int>(justInNum1.begin(), justInNum1.end()), vector<int>(justInNum2.begin(), justInNum2.end()))
    }
};
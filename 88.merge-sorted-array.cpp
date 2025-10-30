// Not in neetcode 150

#include <vector>
#include <iostream>

using namespace std;
class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        int i1 = m - 1;
        int i2 = n - 1;
        int mainIndex = m + n - 1;
        while (i2 >= 0)
        {
            if (i1 >= 0 && nums1[i1] > nums2[i2])
            {
                nums1[mainIndex] = nums1[i1--];
            }
            else
            {
                nums1[mainIndex] = nums2[i2--];
            }
            mainIndex--;
        }
    }
};
int main()
{
    Solution s;
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    int m = 3, n = 3;

    s.merge(nums1, m, nums2, n);

    for (int x : nums1)
        cout << x << " ";
    cout << endl; // Output: 1 2 2 3 5 6
}
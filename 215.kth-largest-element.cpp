#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int findKthLargest(vector<int> &nums, int k)
    {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int n : nums)
        {
            pq.push(n);
            if ((int)pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
};

int main()
{
    vector<int> nums = {3, 2, 3, 1, 2, 4, 5, 5, 6};
    int k = 4;

    Solution sol;
    cout << sol.findKthLargest(nums, k) << endl; // Output: 4

    return 0;
}

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    priority_queue<int, vector<int>, greater<int>> pq;
    int k;
    int findKthLargest(vector<int> &nums, int k)
    {
        this->k = k;
        for (int n : nums)
        {
            pq.push(n);
            if ((int)pq.size() > k)
                pq.pop();
        }
        return pq.top();
    }
    // Added the two functions below to adhrer to Neetcode "Kth Largest Element in a Stream" problem specs
    void KthLargest(int k, vector<int> &nums)
    {
        this->k = k;
        for (int n : nums)
        {
            pq.push(n);
            if ((int)pq.size() > k)
                pq.pop();
        }
    }
    int add(int val)
    {
        pq.push(val);
        if (pq.size() > k)
            pq.pop();
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

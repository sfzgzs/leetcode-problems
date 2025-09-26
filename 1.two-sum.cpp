#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        vector<pair<int, int>> numWithIndex;
        for (int i = 0; i < nums.size(); ++i)
        {
            numWithIndex.push_back({nums[i], i});
        }

        sort(numWithIndex.begin(), numWithIndex.end(), [](const pair<int, int> &a, const pair<int, int> &b)
             { return a.first < b.first; });

        int pFirst = 0, pLast = nums.size() - 1;
        while (pFirst < pLast)
        {
            int sum = numWithIndex[pFirst].first + numWithIndex[pLast].first;
            if (sum == target)
            {
                auto res = {numWithIndex[pFirst].second, numWithIndex[pLast].second};
                auto revRes = {numWithIndex[pLast].second, numWithIndex[pFirst].second};
                return (numWithIndex[pFirst].second > numWithIndex[pLast].second)
                           ? revRes
                           : res;
            }
            else if (sum < target)
            {
                pFirst++;
            }
            else
            {
                pLast--;
            }
        }

        return {};
    }
};

#include <string>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <algorithm>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int> &nums)
    {
        set<vector<int>> res;
        vector<vector<int>> ret;
        unordered_map<int, vector<int>> places;
        for (int i = 0; i < nums.size(); i++)
            places[nums[i]].push_back(i);
        multiset<int> mset(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                int last = -1 * (nums[i] + nums[j]);
                auto search = places.find(last);
                if (search != places.end())
                {
                    for (auto lindex : places[last])
                    {
                        if (lindex > j)
                        {
                            vector<int> addedv({nums[i], nums[j], nums[lindex]});
                            sort(addedv.begin(), addedv.end());
                            res.insert(addedv);
                        }
                    }
                }
            }
        }
        for (auto v : res)
        {
            ret.push_back(vector<int>(v.begin(), v.end()));
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    auto res = s.threeSum(nums);
    for (auto v : res)
    {
        for (auto out : v)
            cout << out << " " << endl;
        cout << endl;
    }
}
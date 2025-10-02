#include <string>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution
{
public:
    int longestConsecutive(vector<int> &nums)
    {
        unordered_set<int> allnums(nums.begin(), nums.end());
        unordered_set<int> starts;
        for (int num : nums)
        {
            auto search = allnums.find(num - 1);
            if (search == allnums.end())
            {
                starts.insert(num);
            }
        }
        int seqcount = 0, maxlen = 0, searchedsofar = 0;
        for (int start : starts)
        {
            searchedsofar = 1;
            seqcount = 1;

            int elem = start + 1;
            auto search = allnums.find(elem);
            while (search != allnums.end())
            {
                seqcount++;
                searchedsofar++;
                elem++;
                search = allnums.find(elem);
            }
            if (seqcount > maxlen)
                maxlen = seqcount;
            if (maxlen > allnums.size() - searchedsofar)
                return maxlen;
        }
        return maxlen;
    }
};

int main()
{
    Solution s;
    vector<int> nums = {2, 20, 4, 10, 3, 4, 5};
    cout << s.longestConsecutive(nums) << endl;
}
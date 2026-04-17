#include <climits>
#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;
class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        vector<bool> res(candies.size(), false);
        map<int, vector<int>> candies_kids; // should be sorted (increasing) by # of candies
        for (int i = 0; i < candies.size(); i++)
            candies_kids[candies[i]].push_back(i);
        auto &lastElement = candies_kids.rbegin();
        int maxCandy = lastElement.first() : for (auto &[candyCount, kidIndices] : candies_kids)
        {
            if (candyCount + extraCandies > maxCandy)
                for (int kid : kidIndices)
                {
                    res[kid] = true;
                }
        }
    }
};
int main()
{
    Solution s;
    vector<int> inp = {2, 3, 5, 1, 3};
    cout << s.kidsWithCandies(inp) << "\n";
}
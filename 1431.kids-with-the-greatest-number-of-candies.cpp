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
        int maxCandy = 0;

        for (int c : candies)
            maxCandy = max(maxCandy, c);

        vector<bool> res;

        for (int c : candies)
            res.push_back(c + extraCandies >= maxCandy);

        return res;
    }
};
int main()
{
    Solution s;
    vector<int> inp = {2, 3, 5, 1, 3};
    cout << s.kidsWithCandies(inp) << "\n";
}
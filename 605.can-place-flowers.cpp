#include <vector>
#include <iostream>
using namespace std;
class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int count = 0;

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == flowerbed.size() - 1) || (flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight)
                {
                    flowerbed[i] = 1; // plant
                    count++;
                    if (count >= n)
                        return true;
                }
            }
        }

        return count >= n;
    }
};

int main()
{
    Solution s;
    vector<int> ints = {1, 0, 0, 0, 1};
    cout << s.canPlaceFlowers(ints, 1);
    return 0;
}

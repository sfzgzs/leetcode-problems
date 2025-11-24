#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> fib = {0, 1, 2};
    int climbStairs(int n)
    {
        if (fib.size() > n)
            return fib[n];

        while (fib.size() <= n)
        {
            int size = fib.size();
            fib.push_back(fib[size - 1] + fib[size - 2]);
        }
        return fib[n];
    }
};

int main()
{
    Solution s;
    int result = s.climbStairs(3);
    cout << result << endl;
    return 0;
}
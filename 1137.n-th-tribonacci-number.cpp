#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;
class Solution
{
public:
    int tribonacci(int n)
    {
        if (n == 0)
            return 0;
        if (n == 1 || n == 2)
            return 1;
        int counter = 3;
        int n1 = 0, n2 = 1, n3 = 1;
        while (counter <= n)
        {
            int tmp = n1 + n2 + n3;
            n1 = n2;
            n2 = n3;
            n3 = tmp;
            counter++;
        }
        return n3;
    }
};
int main()
{
    Solution s;
    cout << s.tribonacci(3);
}
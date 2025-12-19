#include <iostream>

using namespace std;

class Solution
{
public:
    int hammingWeight(int n)
    {
        char c = 0b0;
        for (char i = 0; i < 32; i++)
        {
            if (n & 1)
                c++;
            n = n >> 1;
        }
        return c;
    }
};
int main()
{
    Solution s;
    int32_t inp = 0b00000000000000000000000000010111;
    cout << "res is " << s.hammingWeight(inp) << "\n";
}
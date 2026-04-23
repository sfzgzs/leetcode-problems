class Solution
{
public:
    int numTilings(int n)
    {
        const int MOD = 1e9 + 7;

        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        if (n == 3)
            return 5;

        long n1 = 1, n2 = 2, n3 = 5;
        // f(n) = 2*f(n-1) + f(n-3)
        for (int i = 4; i <= n; i++)
        {
            long tmp = (2 * n3 + n1) % MOD;
            n1 = n2;
            n2 = n3;
            n3 = tmp;
        }

        return n3;
    }
};

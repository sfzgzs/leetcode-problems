class Solution
{
public:
    vector<int> countBits(int n)
    {
        vector<int> bits(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            bits[i] = bits[i >> 1] + (i & 1);
        }

        return bits;
    }
    // Second attempt
    vector<int> countBits(int n)
    {
        int offset = 1;
        vector<int> bits(n + 1, 0);

        for (int i = 1; i <= n; i++)
        {
            if (2 * offset == i)
                offset *= 2;
            bits[i] = 1 + bits[i - offset];
        }

        return bits;
    }
};

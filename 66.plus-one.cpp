class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        int carry = 1;
        for (int i = digits.size() - 1; i >= 0; i--)
        {
            int res = digits[i] + carry;
            digits[i] = res % 10;
            carry = res / 10;
        }
        if (carry > 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};
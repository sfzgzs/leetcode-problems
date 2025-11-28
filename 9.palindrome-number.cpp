class Solution
{
public:
    bool isPalindrome(int x)
    {
        if (x < 0)
            return false;
        string xstr = std::to_string(x);
        int i = 0;
        int j = xstr.size() - 1;
        while (i <= j)
        {
            if (xstr[i] != xstr[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
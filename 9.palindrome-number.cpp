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
    bool isPalindromeStack(int x)
    {
        if (x < 0)
            return false;
        stack<int> st;
        int rem = x;
        while (rem != 0)
        {
            st.push(rem % 10);
            rem /= 10;
        }
        rem = x;
        while (!st.empty())
        {
            if (st.top() != rem % 10)
                return false;
            rem /= 10;
            st.pop();
        }
        return true;
    }
};
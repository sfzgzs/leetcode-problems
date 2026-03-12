// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution
{
public:
    int firstBadVersion(int n)
    {
        int first = 1;
        int last = n;
        while (true)
        {
            if (first == last)
                return first;
            if (isBadVersion(first + (last - first) / 2))
                last = first + (last - first) / 2;
            else
                first = first + (last - first) / 2 + 1;
        }
    }
};
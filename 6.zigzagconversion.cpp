# Intuition
<!-- Describe your first thoughts on how to solve this problem. -->

# Approach
<!-- Describe your approach to solving the problem. -->

# Complexity
- Time complexity:
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    string convert(string s, int numRows) {
        string res("");
        if(numRows == 1 || s.size() == 1)
            return s;

        for(int i = 0 ; i< s.size(); i+= (2 * numRows - 2))
            res.push_back(s.at(i));
        for (int i = 1; i < numRows-1; i++) {
            int tmpDiff = 2*numRows - 2 * i - 2;
            for(int j = i; j < s.size(); j+= (2*numRows - 2)) {
                res.push_back(s.at(j));
                if(j+tmpDiff < s.size())
                    res.push_back(s.at(j+tmpDiff));

            }
        }

        for(int i = numRows-1 ; i< s.size(); i+= (2 * numRows - 2))
            res.push_back(s.at(i));
        return res;
    }
};
```

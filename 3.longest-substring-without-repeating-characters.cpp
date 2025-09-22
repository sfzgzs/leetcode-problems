/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 */

// @lc code=start
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mapOfChars{};
        int startIndex = 0, maxCount = 0;
        for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (mapOfChars.find(c) != mapOfChars.end() && mapOfChars[c] >= startIndex) {
            startIndex = mapOfChars[c] + 1;
        }
        mapOfChars[c] = i;
        maxCount = max(maxCount, i - startIndex + 1);
    }

        return maxCount;
    }
};
// @lc code=end

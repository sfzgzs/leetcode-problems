class Solution {
public:
    unordered_map<char, string> mp = {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
    };

    string alldigits = "";

    void next(int index, vector<string>& all, string last) {
        if (index == alldigits.size()) {
            all.push_back(last);
            return;
        }

        string letters = mp[alldigits[index]];
        for (int i = 0; i < letters.size(); i++) {
            next(index + 1, all, last + letters[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> strs;
        if (digits.empty()) return strs;

        alldigits = digits;
        next(0, strs, "");
        return strs;
    }
};

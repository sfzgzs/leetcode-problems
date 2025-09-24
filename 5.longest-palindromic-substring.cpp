#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

class Solution {
public:
    int isPal(string &s, vector<vector<int>> &mat, int i, int j){
        if(mat[i][j] != -1)
            return mat[i][j];
        if(j - i < 2) {
                mat[i][j] = (s[i] == s[j]) ? 1 : 0;
                return mat[i][j];
            }
        if(s.at(i) != s.at(j)) {
                mat[i][j] = 0;
                return 0;
        } else {
               int tmp = isPal(s, mat, i+1, j-1);
                mat[i][j] = tmp;
                return tmp;
        }
    }
    string longestPalindrome(string s) {
        int strSize = s.size();
        vector<vector<int>> m;
        for(int i = 0; i < strSize; i++) {
                vector <int> row(strSize, -1);
                m.push_back(row);
        }

        for(int len = strSize; len>1; len--){
            for(int startIndex = 0; startIndex <= strSize - len; startIndex++)
                if(isPal(s, m, startIndex, startIndex + len - 1 ) == 1)
                    return s.substr(startIndex, len);
        }
        return s.substr(0,1);
    }
};

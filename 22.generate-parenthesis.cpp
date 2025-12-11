#include <iostream>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
    int parnum = 0;
    string ressofar = "";
    vector<string> results;
    void backtrack(int curropen, int currclose)
    {
        if (curropen == currclose && curropen == parnum)
        {
            results.push_back(ressofar);
            return;
        }
        string tmp = ressofar;
        if (curropen < parnum)
        {
            ressofar += "(";
            backtrack(curropen + 1, currclose);
        }
        if (currclose < curropen)
        {
            ressofar = tmp;
            ressofar += ")";
            backtrack(curropen, currclose + 1);
        }
    }
    vector<string> generateParenthesis(int n)
    {
        parnum = n;
        backtrack(0, 0);
        return results;
    }
};

int main()
{
    Solution s;
    auto res = s.generateParenthesis(3);
    for (auto v : res)
    {
        cout << "V: " << v << endl;
    }
}

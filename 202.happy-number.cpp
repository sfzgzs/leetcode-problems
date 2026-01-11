#include <vector>
#include <unordered_set>
#include <iostream>
using namespace std;
void printvector(const vector<int> &st, string str = "")
{
    if (str != "")
        cout << str << "\n";
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printset(const unordered_set<int> &mySet, string str = "")
{
    std::cout << "Elements of the set " << str;
    for (auto const &element : mySet)
    {
        std::cout << element << " ";
    }
    std::cout << std::endl;
}
class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> res;
        vector<int> digits;
        while (true)
        {
            while (n != 0)
            {
                digits.push_back(n % 10);
                n = n / 10;
            }
            printvector(digits, "digits ");
            n = 0;
            for (int el : digits)
            {
                n += el * el;
            }
            if (n == 1)
                return true;
            if ((res.find(n) != res.end()))
                return false;
            res.insert(n);
            printset(res, "results so far ");
            digits.clear();
        }
        return true;
    }
};
int main()
{
    Solution sol;
    cout << sol.isHappy(19);
}
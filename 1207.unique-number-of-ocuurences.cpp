#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void printMap(unordered_map<int, int> m)
{
    for (auto &pair : m)
        cout << pair.first << ": " << pair.second << endl;
}

class Solution
{
public:
    bool uniqueOccurrences(vector<int> &arr)
    {
        unordered_map<int, int> occ;
        for (int &num : arr)
            occ[num]++;
        unordered_map<int, int> reps;

        for (auto &[key, times] : occ)
        {
            if (reps[times] != 0)
                return false;
            reps[times]++;
        }
        return true;
    }
};

int main()
{
    Solution s;
    vector<int> ins = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
    cout << s.uniqueOccurrences(ins);
    return 0;
}
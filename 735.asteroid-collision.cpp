#include <algorithm>
#include <stack>
#include <vector>
#include <iostream>

using namespace std;

void printvector(const vector<int> &st)
{
    for (int i = 0; i < st.size(); i++)
        cout << st[i] << " ";
    cout << endl;
}
void printstack(stack<int> st)
{
    cout << "printing stack of " << st.size() << " elements!\n";
    stack<int> tempStack = st;

    while (!tempStack.empty())
    {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;
}

class Solution
{
public:
    vector<int> asteroidCollision(vector<int> &asteroids)
    {
        stack<int> astroStack;

        for (int currentAstro : asteroids)
        {
            bool alive = true;

            while (alive && !astroStack.empty() && astroStack.top() > 0 && currentAstro < 0)
            {
                if (abs(astroStack.top()) < abs(currentAstro))
                {
                    astroStack.pop(); // top explodes, keep going
                }
                else if (abs(astroStack.top()) == abs(currentAstro))
                {
                    astroStack.pop(); // both explode
                    alive = false;
                }
                else
                {
                    alive = false; // current explodes
                }
            }

            if (alive)
            {
                astroStack.push(currentAstro);
            }
        }

        vector<int> res(astroStack.size());
        for (int i = astroStack.size() - 1; i >= 0; i--)
        {
            res[i] = astroStack.top();
            astroStack.pop();
        }
        return res;
    }
};
int main()
{
    Solution s;
    vector<int> ints = {5, 10, -5};
    printvector(s.asteroidCollision(ints));
    return 0;
}
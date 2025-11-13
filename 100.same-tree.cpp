#include <cmath>
#include <iostream>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    bool sameHelper(TreeNode *p, TreeNode *q, bool &same)
    {
        if (!same)
            return false;
        if (!p && !q)
            return true;
        if (!p || !q)
            return false;
        if (p->val != q->val)
            return false;
        bool l = sameHelper(p->left, q->left, same);
        if (!same)
            return false;
        bool r = sameHelper(p->right, q->right, same);
        if (!same)
            return false;
        return l && r;
    }
    bool isSameTree(TreeNode *p, TreeNode *q)
    {
        bool same = true;
        bool res = sameHelper(p, q, same);
        return same && res;
    }
};

int main()
{
    Solution s;
    TreeNode *root1 = new TreeNode(1);
    root1->left = new TreeNode(2);
    root1->right = new TreeNode(3);
    root1->left->left = new TreeNode(4);
    root1->left->right = new TreeNode(5);

    TreeNode *root2 = new TreeNode(1);
    root2->left = new TreeNode(2);
    root2->right = new TreeNode(3);
    root2->left->left = new TreeNode(4);
    root2->left->right = new TreeNode(5);

    int result = s.isSameTree(root1, root2);

    cout << result << endl;

    return 0;
}
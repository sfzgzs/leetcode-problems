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
    int depthHelper(TreeNode *root, bool &balanced)
    {
        if (!balanced)
            return 0;
        if (root == nullptr)
            return 0;
        int dl = depthHelper(root->left, balanced);
        if (!balanced)
            return 0;
        int dr = depthHelper(root->right, balanced);
        if (!balanced)
            return 0;

        if (abs(dr - dl) > 1)
            balanced = false;
        return max(dr, dl) + 1;
    }
    bool isBalanced(TreeNode *root)
    {
        bool balanced = true;
        int tmp = depthHelper(root, balanced);
        return balanced;
    }
};

int main()
{
    Solution s;
    TreeNode *root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    cout << s.isBalanced(root) << endl;
}
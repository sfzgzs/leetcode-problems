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
    // returns <maxdepth,maxdiam>
    pair<int, int> diamHelper(TreeNode *root)
    {
        if (root == nullptr)
            return pair<int, int>(0, 0);
        pair<int, int> helperRight = diamHelper(root->right);
        pair<int, int> helperLeft = diamHelper(root->left);
        int maxDiam = max(helperRight.second, helperLeft.second);
        int tmpdepth = helperRight.first + helperLeft.first;
        pair<int, int> p;
        p.second = max(maxDiam, tmpdepth);
        p.first = max(helperLeft.first, helperRight.first) + 1;
        cout << "root " << root->val << " max depth " << p.first << "diam " << p.second << endl;
        return p;
    }
    int diameterOfBinaryTree(TreeNode *root)
    {
        return diamHelper(root).second;
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

    int result = s.diameterOfBinaryTree(root);

    cout << "Diameter of the binary tree: " << result << endl;

    return 0;
}
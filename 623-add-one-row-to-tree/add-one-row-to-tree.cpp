/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int nValue;
    void dfs(TreeNode* root, int depth) {
        if (!root) {
            return;
        }
        if (depth == 0) {
            TreeNode* nLeft = new TreeNode(nValue, root->left, NULL);
            TreeNode* nRight = new TreeNode(nValue, NULL, root->right);
            root->left = nLeft;
            root->right = nRight;
            return;
        }
        dfs(root->left, depth - 1);
        dfs(root->right, depth - 1);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* nRoot = new TreeNode(val, root, NULL);
            return nRoot;
        }
        nValue = val;
        dfs(root, depth - 2);
        return root;
    }
};
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    pair<int,int> recursive(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> left = recursive(root->left);
        pair<int,int> right = recursive(root->right);
        int height = max(left.second, right.second) +1;
        int len = left.second+right.second + 1;
        return {max({left.first, right.first, len}) , height};
    }
    int diameterOfBinaryTree(TreeNode* root) {
        pair<int,int> p = recursive(root);
        return p.first-1;
    }
};
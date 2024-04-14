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
    int helper(TreeNode* root, bool isLeft){
        if(!root){
            return 0;
        }
        int left = helper(root->left, true);
        int right = helper(root->right, false);
        int sum = left + right;
        if(isLeft && !root->left && !root->right){
            sum+=root->val;
        }
        return sum;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        return helper(root, false);
    }
};
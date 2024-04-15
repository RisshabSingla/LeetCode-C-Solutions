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
    int total_sum = 0;
    void calcSum(TreeNode* root, int curr){
        if(!root){
            total_sum+=curr;
            return;
        }
        if(!root->left && !root ->right){
            total_sum+= curr*10 + root->val;
            return;
        }
        if(root->left != NULL){
            calcSum(root->left, curr*10 + root->val);
        }
        if(root->right != NULL){
            calcSum(root->right, curr*10 + root->val);
        }
    }
    int sumNumbers(TreeNode* root) {
        calcSum(root,0);
        return total_sum;
    }
};
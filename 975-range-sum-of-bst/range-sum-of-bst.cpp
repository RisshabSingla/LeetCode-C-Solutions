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
    int sum_g;
    int low_g;
    int high_g;
    void calcInorder(TreeNode* root){
        if(!root){
            return;
        }
        calcInorder(root->left);
        if(low_g <= root->val && root->val <= high_g){
            sum_g+= root->val;
        }
        calcInorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        sum_g = 0;
        low_g = low;
        high_g = high;
        calcInorder(root);
        return sum_g;
    }
};
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
    vector<int> inorder;
    void inorderTraversal(TreeNode* root) {
        if(root == NULL){
            return;
        }
        inorderTraversal(root->left);
        inorder.push_back(root->val);
        inorderTraversal(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        inorderTraversal(root);
        int min_diff = INT_MAX;
        for(int i = 1; i<inorder.size(); i++){
            int diff = abs(inorder[i-1] - inorder[i]);
            if(diff<min_diff){
                min_diff = diff;
            }
        }
        return min_diff;   
    }
};
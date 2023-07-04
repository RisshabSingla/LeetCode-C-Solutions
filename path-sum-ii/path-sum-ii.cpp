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
    void helper(TreeNode* root, int targetSum, vector<int> nodes, vector<vector<int>> &ans){
        
        if(root == NULL){
            return;
        }
        int data = root->val;
        nodes.push_back(data);
        if(!root->left && !root->right && root->val == targetSum){
            ans.push_back(nodes);
        }
        helper(root->left, targetSum-data, nodes,ans);
        helper(root->right, targetSum-data, nodes,ans);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        if(root == NULL){
            return ans;
        }

        vector<int> nodes;
        helper(root, targetSum, nodes, ans);
        return ans;
    }
};
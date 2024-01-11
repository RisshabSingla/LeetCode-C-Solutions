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
    int ans = 0;
    void dfs(TreeNode* root, vector<TreeNode*>&ancestor){
        if(!root){
            return;
        }
        for(int i = 0; i<ancestor.size(); i++){
            ans = max(ans, 
            abs(ancestor[i]->val - root->val));
        }
        ancestor.push_back(root);
        dfs(root->left, ancestor);
        dfs(root->right, ancestor);
        ancestor.pop_back();
    }
    int maxAncestorDiff(TreeNode* root) {
        vector<TreeNode*> ancestor;
        dfs(root, ancestor);
        return ans;
    }
};
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

    void dfs2(TreeNode* root, int minAncestor, int maxAncestor){
        if(!root){
            return;
        }
        int a = min(minAncestor, root->val);
        int b = max(maxAncestor, root->val);
        ans = max(ans, abs(a-b));
        dfs2(root->left, a, b);
        dfs2(root->right, a,b);
    }
    int maxAncestorDiff(TreeNode* root) {
        // vector<TreeNode*> ancestor;
        // dfs(root, ancestor);
        dfs2(root, root->val, root->val);
        return ans;
    }
};
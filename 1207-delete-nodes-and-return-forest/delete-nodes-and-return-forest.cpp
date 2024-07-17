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
    void dfs(TreeNode* root, unordered_set<int>& st, vector<TreeNode*> &ans,
             bool isRoot) {
        if (!root) {
            return;
        }
        if (st.count(root->val)) {
            dfs(root->left, st, ans, true);
            dfs(root->right, st, ans, true);
            return;
        }
        if (isRoot) {
            ans.push_back(root);
        }
        TreeNode* left = root->left;
        TreeNode* right = root->right;
        if (left && st.count(left->val)) {
            root->left = NULL;
        }
        if (right && st.count(right->val)) {
            root->right = NULL;
        }
        dfs(left, st, ans, false);
        dfs(right, st, ans, false);
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& del) {
        unordered_set<int> st;
        for (auto i : del) {
            st.insert(i);
        }
        vector<TreeNode*> ans;
        dfs(root, st, ans, true);
        return ans;
    }
};
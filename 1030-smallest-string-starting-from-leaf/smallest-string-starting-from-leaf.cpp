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
    string smallestString = "~";
    void dfs(TreeNode* root, string&str){
        if(!root){
            return;
        }
        str.push_back('a'+ root->val);
        if(!root->left && !root->right){
            reverse(str.begin(), str.end());
            smallestString = min(smallestString, str);
            reverse(str.begin(), str.end());
        }
        dfs(root->left, str);
        dfs(root->right, str);
        str.pop_back();

    }
    string smallestFromLeaf(TreeNode* root) {
        string str = "";
        dfs(root, str);
        return smallestString;
    }
};
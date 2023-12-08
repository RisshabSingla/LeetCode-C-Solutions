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
    string helper(TreeNode* root){
        if(root == NULL){
            return "()";
        }
        if(root->left == NULL && root->right == NULL){
            string str = "(" + to_string(root->val) + ")";
            return str;
        }

        string left = helper(root->left);
        string right = helper(root->right);
        string str = '(' + to_string(root->val) + left;
        if(right != "()"){
            str = str + right;
        }
        str = str + ')';
        return str;
    }

    string tree2str(TreeNode* root) {
        if(root == NULL){
            return "";
        }
        if(root->left == NULL && root->right == NULL){
            string str = to_string(root->val);
            return str;
        }
        
        string left = helper(root->left);
        string right = helper(root->right);
        string str = to_string(root->val) + left;
        if(right != "()"){
            str = str + right;
        }
        // str = str + ';
        return str;
        
    }
};
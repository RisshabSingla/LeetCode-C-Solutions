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
    int number = 0;
    bool isPalindromic(unordered_map<int,int> &curr){
        bool odd = false;
        for(auto &i: curr){
            if(i.second % 2){
                if(odd){
                    return false;
                }
                odd = true;
            }
        }
        return true;
    }
    void recursion(TreeNode* root, unordered_map<int,int>&curr){
        if(!root-> left && !root->right){
            if(isPalindromic(curr)){
                number++;
            }
            return;
        }
        if(root->left){
            curr[root->left->val]++;
            recursion(root->left, curr);
            curr[root->left->val]--;
        }
        if(root->right){
            curr[root->right->val]++;
            recursion(root->right, curr);
            curr[root->right->val]--;
        }
    }
    int pseudoPalindromicPaths (TreeNode* root) {
        unordered_map<int,int> curr;
        curr[root->val]++;
        recursion(root, curr);
        return number;
    }
};
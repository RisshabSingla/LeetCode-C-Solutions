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
    int count;
    pair<int,int> helper(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> lft = helper(root->left);
        pair<int,int> rgt = helper(root->right);
        int sum = lft.first + rgt.first + root->val;
        int num = lft.second + rgt.second + 1;
        if(sum/num == root->val){
            // cout<<"Val: "<<root->val<<endl;
            count++;
        }
        return {sum, num};
    }
    int averageOfSubtree(TreeNode* root) {
        count = 0;
        helper(root);
        return count;
    }
};
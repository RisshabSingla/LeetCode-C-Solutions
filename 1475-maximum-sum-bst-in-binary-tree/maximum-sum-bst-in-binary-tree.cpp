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
    long long highest_sum = 0;
    // bool, sum, mini, maxi
    vector<long long> findMaxSum(TreeNode* root){
        if(!root){
            return {1, 0, INT_MAX, INT_MIN};
        }
        if(!root->left && !root->right){
            // cout<<"For root: "<<root->val<<" returning true\n";
            highest_sum = max(highest_sum, (long long)(root->val));
            return {1, root->val, root->val, root->val};
        }

        vector<long long> left = findMaxSum(root->left);
        vector<long long> right = findMaxSum(root->right);
        if(left[0] == 0 || right[0] == 0 || left[3] >= root->val || right[2] <= root->val){
            // cout<<"For root: "<<root->val<<" returning false\n";
            return {0, 0, INT_MAX, INT_MIN};
        }
        highest_sum = max(highest_sum, (left[1]+right[1] + root->val));
        return {1, left[1]+right[1] + root->val,min(left[2], (long long)(root->val)), max(right[3], (long long)(root->val))};
    }
    int maxSumBST(TreeNode* root) {
        findMaxSum(root);
        return highest_sum;
    }
};
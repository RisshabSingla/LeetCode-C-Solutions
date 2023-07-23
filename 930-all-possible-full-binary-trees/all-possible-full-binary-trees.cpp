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

    vector<TreeNode*> helper(int n, vector<vector<TreeNode*>> &dp){
        if(n % 2 == 0){
            return {};
        }
        if(n == 1){
            TreeNode* root = new TreeNode(0);
            return {root};
        }

        if(dp[n].size() != 0){
            return dp[n];
        }

        vector<TreeNode*> ans;
        for(int i = 1; i<n; i+=2){
            vector<TreeNode*> left_possible = helper(i, dp);
            vector<TreeNode*> right_possible = helper(n-1-i, dp);

            for(auto lft : left_possible){
                for(auto rgt : right_possible){
                    TreeNode* root = new TreeNode(0);
                    root->left = lft;
                    root->right = rgt;
                    ans.push_back(root);
                }
            }
        }
        dp[n] = ans;
        return ans;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<TreeNode*> ans;
        if(n%2 == 0){
            return {};
        }
        vector<vector<TreeNode*>> dp(n+1);
        return helper(n, dp);
    }
};
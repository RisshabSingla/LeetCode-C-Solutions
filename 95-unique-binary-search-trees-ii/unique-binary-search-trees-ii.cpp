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
    vector<TreeNode*> helper(int start, int end){
        vector<TreeNode*> a;
        if(start>end){
            a.push_back(NULL);
            return a;
        }

        if(start == end){
            TreeNode* root = new TreeNode(start);
            a.push_back(root);
            return a;
        }
        
        vector<TreeNode*> ans;
        for(int i = start; i<=end; i++){
            vector<TreeNode*> lft = helper(start, i-1);
            vector<TreeNode*> rgt = helper(i+1, end);
            for(int a = 0; a<lft.size(); a++){
                for(int b = 0; b<rgt.size(); b++){
                    TreeNode* root = new TreeNode(i);
                    root->left = lft[a];
                    root->right = rgt[b];
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
    vector<TreeNode*> generateTrees(int n) {
        return helper(1, n);
    }
};
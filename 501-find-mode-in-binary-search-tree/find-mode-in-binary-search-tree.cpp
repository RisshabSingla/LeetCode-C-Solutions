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
    map<int,int> freq;
    void findInorder(TreeNode* root){
        if(!root){
            return;
        }
        findInorder(root->left);
        freq[root->val]++;
        findInorder(root->right);
    }
    vector<int> findMode(TreeNode* root) {
        findInorder(root);
        int highest_count = -1;
        int highest = -1;
        vector<int> ans;
        for(auto i: freq){
            if(i.second > highest_count){
                vector<int> a;
                highest_count = i.second;
                a.push_back(i.first);
                ans = a;
            }else if(i.second == highest_count){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
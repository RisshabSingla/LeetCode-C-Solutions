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
    int findHeight(TreeNode* root) {
        if (!root) {
            return 0;
        }
        return 1 + max(findHeight(root->left), findHeight(root->right));
    }
    void populateAns(TreeNode* root, int row, int col,
                     vector<vector<string>>& ans, int& height) {
        if (!root) {
            return;
        }
        ans[row][col] = to_string(root->val);
        if(!root->left && !root->right){
            return;
        }
        int left = col - (1<<(height-row-1));
        int right = col + (1<<(height-row-1));
        // cout<<"left: "<<left<<" right: "<<right<<"\n";
        populateAns(root->left, row+1, left, ans, height);
        populateAns(root->right, row+1, right, ans, height);
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int height = findHeight(root) - 1;
        int cols = (1 << (height + 1)) - 1;
        vector<vector<string>> ans(height + 1, vector<string>(cols, ""));
        // cout<<"height: "<<height<<" cols: "<<cols<<'\n';
        populateAns(root, 0, (cols-1)/2, ans, height);
        return ans;
    }
};
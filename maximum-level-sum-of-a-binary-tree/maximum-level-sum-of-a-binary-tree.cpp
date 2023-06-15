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
    int maxLevelSum(TreeNode* root) {
        pair<int,int> ans;
        ans.first = 1;
        ans.second = root->val;
        vector<TreeNode*> level;
        level.push_back(root);
        int height = 1;
        while(level.size() != 0){
            vector<TreeNode*> nxt_level;
            int sum = 0;
            for(int i = 0; i<level.size(); i++){
                TreeNode* node = level[i];
                sum+=node->val;
                if(node->left != NULL){
                    nxt_level.push_back(node->left);
                }
                if(node->right != NULL){
                    nxt_level.push_back(node->right);
                }
            }
            if(sum > ans.second){
                ans.second = sum;
                ans.first = height;
            }
            if(sum == ans.second){
                ans.first = min(height, ans.first);
            }
            height++;
            level = nxt_level;
        }
        cout<<ans.second<<endl;
        return ans.first;
    }
};
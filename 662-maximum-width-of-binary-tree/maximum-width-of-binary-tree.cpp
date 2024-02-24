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
    int widthOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int ans = 1;
        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0LL});
        while(!q.empty()){
            int nodes  = q.size();
            int starting = q.front().second;
            int ending = q.back().second;
            ans = max(ans, ending-starting+1);
            for(int i=0; i<nodes; i++){
                pair<TreeNode*, int> p = q.front();
                q.pop();
                int index = p.second-starting;
                if(p.first->left){
                    q.push({p.first->left, 2LL*index+1});
                }
                if(p.first->right){
                    q.push({p.first->right, 2LL*index+2});
                }
            }
        }
        return ans;
    }
};
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
    int findBottomLeftValue(TreeNode* root) {
        if(!root){
            return 0;
        }

        queue<TreeNode*> q;
        int ans = root->val;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                if(!q.empty()){
                    ans = q.front()->val;
                    q.push(NULL);
                }
                continue;
            }
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        return ans;
    }
};
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
    vector<int> rightSideView(TreeNode* root) {
        
        vector<int> ans;
        if(!root){
            return ans;
        }
        // vector<int> curr;

        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        TreeNode* prev = root;
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front == NULL){
                if(!q.empty()){
                    q.push(NULL);
                }
                ans.push_back(prev->val);
                continue;
            }
            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
            prev = front;
        }
        return ans;
    }
};
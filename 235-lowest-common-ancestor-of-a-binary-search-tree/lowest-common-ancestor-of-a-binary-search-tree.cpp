/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* other) {
        unordered_map<TreeNode*, TreeNode*> parents;
        parents[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* front = q.front();
            q.pop();
            if(front->left){
                parents[front->left] = front;
                q.push(front->left);
            }
            if(front->right){
                parents[front->right] = front;
                q.push(front->right);
            }
        }
        unordered_set<TreeNode*> pred;
        while(p || parents[p]){
            pred.insert(p);
            // pred.push_back(p);
            p = parents[p];
        }

        while(other || parents[other]){
            if(pred.count(other)){
                return other;
            }
            other = parents[other];
        }
        return NULL;
    }
};
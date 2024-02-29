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
    bool isEvenOddTree(TreeNode* root) {
        bool ans = true;
        int level = 0;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        int prev = INT_MIN;
        while (!q.empty()) {
            TreeNode* front = q.front();
            q.pop();
            if (!front) {
                level++;
                if(level % 2){
                    prev = INT_MAX;
                }else{
                    prev = INT_MIN;
                }
                if (!q.empty()) {
                    q.push(NULL);
                }
                continue;
            }
            if ((front->val % 2 == 0 && level % 2 == 0) ||
                (front->val % 2 == 1 && level % 2 == 1)) {
                // cout<<"different: "<<front->val<<"\n";
                ans = false;
                break;
            }

            if(level % 2 == 0){
                if(front->val <= prev){
                    ans = false;
                    // cout<<"even level not okay: "<<front->val<<" prev: "<<prev<<"\n";
                    break;
                }
                prev = front->val;
            }else{
                if(front->val >= prev){
                    // cout<<"odd level not okay: "<<front->val<<" prev: "<<prev<<"\n";
                    ans = false;
                    break;
                }
                prev = front->val;
            }

            if (front->left) {
                q.push(front->left);
            }
            if (front->right) {
                q.push(front->right);
            }
        }
        return ans;
    }
};
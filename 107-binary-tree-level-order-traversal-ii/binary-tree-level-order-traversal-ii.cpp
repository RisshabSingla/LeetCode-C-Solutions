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
    void helper(vector<TreeNode*> a, vector<vector<int>> &ans){
        if(a.size() == 0){
            return;
        }
        vector<TreeNode*> new_a;
        vector<int> b;
        for(int i = 0; i<a.size(); i++){
            b.push_back(a[i]->val);
            if(a[i]->left){
                new_a.push_back(a[i]->left);
            }
            if(a[i]->right){
                new_a.push_back(a[i]->right);
            }
        }

        helper(new_a, ans);
        ans.push_back(b);
    }


    vector<vector<int>> rev(TreeNode*root){
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        vector<int> temp;
        while (!q.empty()) {
            int size = q.size();
            for(int i = 0; i < size; i++) {
                auto tempNode = q.front();
                if (tempNode->left){
                    q.push(tempNode->left);
                }
                if (tempNode->right){
                    q.push(tempNode->right);
                }
                temp.push_back(tempNode->val);
                q.pop();
            }
            ans.push_back(temp);
            temp.clear();
        }   
        reverse(ans.begin(), ans.end());
        return ans;
    }

    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        return rev(root);
        
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        vector<TreeNode*> a;
        a.push_back(root);
        helper(a, ans);
        return ans;
    }
};
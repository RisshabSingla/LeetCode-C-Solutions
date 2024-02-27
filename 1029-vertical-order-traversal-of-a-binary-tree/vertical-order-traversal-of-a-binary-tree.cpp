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
    
    // void numberingNodes(TreeNode* root,
    //                    unordered_map<int, vector<int>>& mp, int val) {
    //     if (!root) {
    //         return;
    //     }
    //     mini = min(mini, val);
    //     maxi = max(maxi, val);
    //     mp[val].push_back(root->val);
    //     numberingNodes(root->left, mp, val - 1);
    //     numberingNodes(root->right, mp, val + 1);
    // }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        int mini = INT_MAX;
        int maxi = INT_MIN;
        unordered_map<int, vector<int>> mp;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1000});
        q.push({NULL, 0});
        unordered_map<int,vector<int>> curr;
        while(!q.empty()){
            pair<TreeNode*, int> p = q.front();
            q.pop();
            if(p.first == NULL){
                for(auto&i: curr){
                    sort(i.second.begin(), i.second.end());
                    for(auto &j: i.second){
                        mp[i.first].push_back(j);
                    }
                }
                if(!q.empty()){
                    q.push({NULL, 0});
                }
                curr.clear();
                continue;
            }
            mini = min(mini, p.second);
            maxi = max(maxi, p.second);
            curr[p.second].push_back(p.first->val);
            if(p.first->left){
                q.push({p.first->left, p.second-1});
            }
            if(p.first->right){
                q.push({p.first->right, p.second+1});
            }
        }
        for(int i = mini; i<=maxi; i++){
            ans.push_back(mp[i]);
        }
        return ans;
    }
};
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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,pair<TreeNode*, bool>> mp;
        for(auto &i: descriptions){
            if(mp.count(i[0])){
                // parent is present
                if(mp.count(i[1])){
                    // child is also present
                    if(i[2] == 0){
                        // right
                        mp[i[0]].first->right = mp[i[1]].first;
                        mp[i[1]].second = true;
                    }else{
                        mp[i[0]].first->left = mp[i[1]].first;
                        mp[i[1]].second = true;
                    }
                }else{
                    // child is absent
                    TreeNode* child = new TreeNode(i[1]);
                    mp[i[1]] = {child, true};
                    if(i[2] == 0){
                        // right
                        mp[i[0]].first->right = child;
                    }else{
                        // left
                        mp[i[0]].first->left = child;
                    }
                }
            }else{
                // parent is absent
                TreeNode* parent = new TreeNode(i[0]);
                mp[i[0]] = {parent, false};
                if(mp.count(i[1])){
                    // child is present
                    if(i[2] == 0){
                        // right
                        parent->right = mp[i[1]].first;
                    }else{
                        parent->left = mp[i[1]].first;
                    }
                    mp[i[1]].second = true;
                }else{
                    // child is absent
                    TreeNode* child = new TreeNode(i[1]);
                    mp[i[1]] = {child, true};
                    if(i[2] == 0){
                        // right
                        parent->right = child;
                    }else{
                        // left
                        parent->left = child;
                    }
                }
            }
        }


        TreeNode* root = NULL;
        for(auto &i: mp){
            if(i.second.second == false){
                root = i.second.first;
                break;
            }
        }
        return root;
    }
};
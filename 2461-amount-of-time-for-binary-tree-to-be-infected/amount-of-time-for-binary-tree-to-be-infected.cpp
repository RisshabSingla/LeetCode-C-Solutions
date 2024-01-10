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
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visited;
    TreeNode* startNode;
    int startVal;
    // int max_dist;
    void dfs(TreeNode* root){
        if(!root){
            return;
        }
        if(root->val == startVal){
            startNode = root;
        }
        if(root->left){
            parent[root->left] = root;
        }
        if(root->right){
            parent[root->right] = root;
        }
        dfs(root->left);
        dfs(root->right);
    }
    // int findHeight(TreeNode* root){
    //     if(!root){
    //         return 0;
    //     }
    //     if(root->val  == startVal){
    //         return -100008;
    //         // need to find the distance from the other side
    //     }
    //     return (max(findHeight(root->left), findHeight(root->right)) + 1);
    // }
    int amountOfTime(TreeNode* root, int start) {
        startVal = start;
        parent[root] = NULL;
        dfs(root);
        queue<pair<TreeNode*,int>> q;
        q.push({startNode, 0});
        visited.insert(startNode);
        int max_dist = 0;
        while(!q.empty()){
            pair<TreeNode*,int> p = q.front();
            q.pop();
            // cout<<p.first->val<<" ";
            max_dist = max(max_dist, p.second);
            if(!visited.count(parent[p.first])){
                if(parent[p.first]){
                    q.push({parent[p.first], p.second+1});
                    // parent can be null
                    visited.insert(parent[p.first]);
                }
            }
            if(p.first->left && !visited.count(p.first->left)){
                q.push({p.first->left, p.second+1});
                visited.insert(p.first->left);
            }
            if(p.first->right && !visited.count(p.first->right)){
                q.push({p.first->right, p.second+1});
                visited.insert(p.first->right);
            }
        }
        // cout<<"\n\n";
        return max_dist;
    }
};
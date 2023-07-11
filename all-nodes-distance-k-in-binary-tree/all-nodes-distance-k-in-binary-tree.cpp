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
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> answer;
        if(root == NULL){
            return answer;
        }
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<TreeNode*, TreeNode*> parents;
        // finding all the parents of the nodes for movement in all directions
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            TreeNode* lft = top->left;
            TreeNode* rgt = top->right;
            if(lft!= NULL){
                q.push(lft);
                parents[lft] = top;
            }
            if(rgt!= NULL){
                q.push(rgt);
                parents[rgt] = top;
            }
        }

        vector<TreeNode*> curr;
        set<TreeNode*> visited;
        curr.push_back(target);
        int dist = 0;
        visited.insert(target);
        // iterating over the whole tree
        while(dist<k){
            vector<TreeNode*> nxt;
            // cout<<"Inside while curr is: ";
            for(auto i: curr){
                // if(i == NULL){
                //     continue;
                // }
                // cout<<i->val<<" ";
                TreeNode* lft = i->left;
                TreeNode* rgt = i->right;
                if(lft != NULL && visited.count(lft) == 0){
                    nxt.push_back(lft);
                    visited.insert(lft);
                }
                if(rgt != NULL && visited.count(rgt) == 0){
                    nxt.push_back(rgt);
                    visited.insert(rgt);
                }
                TreeNode* parent = parents[i];
                if(parent != NULL && visited.count(parent) == 0){
                    nxt.push_back(parent);
                    visited.insert(parent);
                }
            }
            // cout<<endl;
            // cout<<"Nxt is: ";
            // for(auto i : nxt){
            //     cout<<i->val<<" ";
            // }
            // cout<<endl;
            dist++;
            curr = nxt;
        }
        
        for(auto i : curr){
            // if(i!= NULL){
                answer.push_back(i->val);
            // }
        }
        return answer;

    }
};
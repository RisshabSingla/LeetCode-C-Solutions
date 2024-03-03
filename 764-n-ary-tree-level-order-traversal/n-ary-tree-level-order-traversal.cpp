/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }
        queue<Node*> q;
        q.push(root);
        q.push(NULL);
        vector<int> curr;
        while(!q.empty()){
            Node* front = q.front();
            q.pop();
            if(!front){
                if(!q.empty()){
                    q.push(NULL);
                }
                ans.push_back(curr);
                curr.clear();
                continue;
            }
            curr.push_back(front->val);
            for(auto&i: front->children){
                if(i!= NULL){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};
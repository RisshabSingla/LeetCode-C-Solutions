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
class BSTIterator {
public:
    vector<int> inorder;
    int current;
    int n;
    void findInorder(TreeNode* root){
        if(!root){
            return;
        }
        findInorder(root->left);
        inorder.push_back(root->val);
        findInorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        findInorder(root);
        current= 0;
        n = inorder.size();
    }
    
    int next() {
        int val = inorder[current];
        current++;
        return val;
    }
    
    bool hasNext() {
        return current<n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
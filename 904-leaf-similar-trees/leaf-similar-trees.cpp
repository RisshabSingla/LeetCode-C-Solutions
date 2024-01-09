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
    vector<int> leaf1;
    vector<int> leaf2;

    void findLeaf(TreeNode* root, int num){
        if(!root){
            return;
        }
        if(!root->left && !root->right){
            if(num == 1){
                leaf1.push_back(root->val);
            }else{
                leaf2.push_back(root->val);
            }
        }
        findLeaf(root->left,num);
        findLeaf(root->right,num);
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        findLeaf(root1,1);
        findLeaf(root2,2);


        int size1 = leaf1.size();
        int size2 = leaf2.size();
        if(size1!= size2){
            return false;
        }

        for(int i = 0; i<leaf1.size(); i++){
            if(leaf1[i]!= leaf2[i]){
                return false;
            }
        }
        // cout<<endl;
        return true;
    }
};
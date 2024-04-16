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
    // int helper(TreeNode* root, bool canRob){
    //     if(!root){
    //         return 0;
    //     }
    //     if(!root->left && !root->right){
    //         if(canRob){
    //             return root->val;
    //         }
    //         return 0;
    //     }

    //     int a = -1;
    //     int b = -1;
    //     int c = -1;
    //     int d = -1;

    //     if(canRob){
    //         // robbing the root
    //         a = helper(root->left, false);
    //         b = helper(root->right, false);

    //         // not robbing the root
    //         c = helper(root->left, true);
    //         d = helper(root->right, true);
    //     }else{
    //         // not robbing the root
    //         c = helper(root->left, true);
    //         d = helper(root->right, true);
    //     }
    //     int val1 = max(a+b+root->val, c+d);
    //     int val2 = c+d;

    //     if(val1>val2){
    //         cout<<"Robbing a: "<<a<<" b: "<<b<<" root: "<<root->val<<" val1: "<<val1<<endl;
    //         return val1;
    //     }else{
    //         cout<<"Robbing c: "<<c<<" d: "<<d<<" root"<<root->val<<" val2: "<<val2<<endl;
    //         return val2;
    //     }
    //     return 0;
    //     // return max((), (c+d));
    // }
    // Pair -> Robbed, not robbed
    pair<int,int> helper(TreeNode* root){
        if(!root){
            return {0,0};
        }
        pair<int,int> lft = helper(root->left);
        pair<int,int> rgt = helper(root->right);
        pair<int,int> ans;
        ans.first = root->val + lft.second + rgt.second;
        ans.second = max({lft.first + rgt.first, lft.first+ rgt.second, lft.second + rgt.first, lft.second+rgt.second});
        // cout<<"answer is: "<<ans.first<<" "<<ans.second<<"\n";
        return ans;
    }
    int rob(TreeNode* root) {
        pair<int, int> ans = helper(root);
        return max(ans.first, ans.second);
        // return max(helper(root, false), helper(root, true));
    }
};
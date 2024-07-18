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
    int pairs = 0;
    vector<int> dfs(TreeNode* root, int distance) {
        if (!root) {
            return {};
        }
        if (!root->left && !root->right) {
            // leaf node
            return {1};
        }
        vector<int> left = dfs(root->left, distance);
        vector<int> right = dfs(root->right, distance);

        for (int i = 0; i < left.size(); i++) {
            for (int j = 0; j < right.size(); j++) {
                int dis = left[i] + right[j];
                if (dis <= distance) {
                    pairs++;
                }
            }
        }

        for(auto &i: left){
            i++;
        }
        for (auto i : right) {
            left.push_back(i+1);
        }
        return left;
    }
    int countPairs(TreeNode* root, int distance) {
        dfs(root, distance);
        return pairs;
    }
};
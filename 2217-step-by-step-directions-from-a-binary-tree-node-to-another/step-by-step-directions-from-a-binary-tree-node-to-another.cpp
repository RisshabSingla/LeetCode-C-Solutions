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
    bool dfs(TreeNode* source, TreeNode* dest, map<TreeNode*, TreeNode*>& mp,
             string& ans, TreeNode* prev) {
        if (source == dest) {
            return true;
        }
        if (!source) {
            return false;
        }

        if (source->left && source->left != prev) {
            ans.push_back('L');
            bool a = dfs(source->left, dest, mp, ans, source);
            if (a) {
                return true;
            }
            ans.pop_back();
        }

        if (source->right && source->right != prev) {
            ans.push_back('R');
            bool a = dfs(source->right, dest, mp, ans, source);
            if (a) {
                return true;
            }
            ans.pop_back();
        }

        if (mp.count(source) && mp[source] != prev) {
            ans.push_back('U');
            bool a = dfs(mp[source], dest, mp, ans, source);
            if (a) {
                return true;
            }
            ans.pop_back();
        }
        return false;
    }
    string getDirections(TreeNode* root, int startVal, int endVal) {
        map<TreeNode*, TreeNode*> mp;
        queue<TreeNode*> qfirst;
        qfirst.push(root);
        TreeNode* starting = NULL;
        TreeNode* ending = NULL;
        while (!qfirst.empty()) {
            TreeNode* front = qfirst.front();
            qfirst.pop();
            if (front->val == startVal) {
                starting = front;
            }
            if (front->val == endVal) {
                ending = front;
            }
            if (front->left) {
                qfirst.push(front->left);
                mp[front->left] = front;
            }
            if (front->right) {
                qfirst.push(front->right);
                mp[front->right] = front;
            }
        }
        string ans = "";
        dfs(starting, ending, mp, ans, NULL);
        return ans;

        // queue <pair<TreeNode*, pair<string, TreeNode*>>> q;
        // q.push({starting, {"", NULL}});
        // while (!q.empty()) {
        //     auto front = q.front();
        //     q.pop();
        //     // cout<<front.first->val <<" "<<front.second.first<<"\n";
        //     if (front.first == ending) {
        //         return front.second.first;
        //     }
        //     if (front.first->left &&
        //         front.second.second != front.first->left) {
        //         string str = front.second.first + 'L';
        //         q.push({front.first->left, {str, front.first}});
        //     }

        //     if (front.first->right &&
        //         front.second.second != front.first->right) {
        //         string str = front.second.first + 'R';
        //         q.push({front.first->right, {str, front.first}});
        //     }

        //     if (mp.count(front.first) &&
        //         front.second.second != mp[front.first]) {
        //         string str = front.second.first + 'U';
        //         q.push({mp[front.first], {str, front.first}});
        //     }
        // }
        // return "";
    }
};
class TrieNode {
public:
    bool isEnding;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        isEnding = false; 
    }
};

class Solution {
public:
    void insert(TrieNode* root, string& word) {
        TrieNode* parent = root;
        for (int i = 0; i < word.length(); i++) {
            if (!parent->children.count(word[i])) {
                parent->children[word[i]] = new TrieNode();
            }
            parent = parent->children[word[i]];
        }
        parent->isEnding = true;
    }
    int findCount(TrieNode* root) {
        TrieNode* parent = root;
        int count = 0;
        queue<pair<TrieNode*, int>> q;
        q.push({parent, 0});
        while (!q.empty()) {
            pair<TrieNode*, int> p = q.front();
            q.pop();
            if (p.first->children.size() == 0) {
                count += (p.second + 1);
            } else {
                for (auto& i : p.first->children) {
                    q.push({i.second, p.second + 1});
                }
            }
        }
        return count;
    }
    int minimumLengthEncoding(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto &i : words) {
            reverse(i.begin(), i.end());
            insert(root, i);
        }
        return findCount(root);
    }
};
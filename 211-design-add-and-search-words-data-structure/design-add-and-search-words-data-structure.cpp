class TrieNode {
public:
    int val;
    bool isEnding;
    unordered_map<int, TrieNode*> children;
    TrieNode() {
        val = -1;
        isEnding = false;
    }
    TrieNode(int value) {
        val = value;
        isEnding = false;
    }
};

class WordDictionary {
public:
    TrieNode* root;
    WordDictionary() { root = new TrieNode(); }
    void addWord(string word) {
        TrieNode* parent = root;
        int index = 0;
        int slen = word.length();
        while (index < slen && parent->children.count(word[index])) {
            parent = parent->children[word[index]];
            index++;
        }
        for (int i = index; i < slen; i++) {
            TrieNode* child = new TrieNode(word[i]);
            parent->children[word[i]] = child;
            parent = parent->children[word[i]];
        }
        parent->isEnding = true;
    }

    bool search(TrieNode* root1, string& word, int index, int& slen) {

        TrieNode* parent = root1;
        // cout << "Word: " << word << " Initial Index: " << index << " slen: " << slen << "\n";
        while (index < slen && word[index] != '.' &&
               parent->children.count(word[index])) {
            // cout<<"Parent before is: "<<char(parent->val)<<"\n";
            // cout<<"Children are: ";
            // for(auto &i: parent->children){
            //     cout<<char(i.first)<<" ";
            // }
            // cout<<"New is: "<<char(parent->children[word[index]]->val)<<"\n";
            parent = parent->children[word[index]];
            index++;
            // cout<<"Parent: "<<char(parent->val)<<" Word: "<<word<<" Initial
            // Index: "<<index<<" slen: "<<slen<<"\n"; cout<<"Children are: ";
            // for(auto &i: parent->children){
            //     cout<<char(i.first)<<" ";
            // }
            // cout<<"\n";
        }
        // cout<<"Outside Parent: "<<char(parent->val)<<" Word: "<<word<<"
        // Initial Index: "<<index<<" slen: "<<slen<<"\n"; cout<<"Children are:
        // "; for(auto &i: parent->children){
        //     cout<<char(i.first)<<" ";
        // }

        // cout << "After while Index: " << index << "\n";
        if (index == slen) {
            if(parent->isEnding){
                return true;
            }
            return false;
        }
        if (word[index] == '.') {
            for (auto i : parent->children) {
                bool a = search(i.second, word, index + 1, slen);
                if (a) {
                    return true;
                }
            }
            return false;
        }
        return false;
    }
    void printTree() {
        queue<TrieNode*> q;
        q.push(root);
        q.push(NULL);
        while (!q.empty()) {
            TrieNode* front = q.front();
            q.pop();
            if (!front) {
                cout << "\n";
                if (!q.empty()) {
                    q.push(NULL);
                }
                continue;
            }
            cout << char(front->val) << " ";
            for (auto& i : front->children) {
                q.push(i.second);
            }
        }
    }
    bool search(string word) {
        // printTree();
        int slen = word.length();
        return search(root, word, 0, slen);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
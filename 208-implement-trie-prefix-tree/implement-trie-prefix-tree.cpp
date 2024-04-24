class TrieNode{
public:
    bool isEnding;
    unordered_map<char, TrieNode*> children;
    TrieNode(){
        isEnding = false;
    }
};

class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* parent = root;
        for(int i = 0; i<word.length(); i++){
            if(!parent->children.count(word[i])){
                parent->children[word[i]] = new TrieNode();
            }
            parent = parent->children[word[i]];
        }
        parent->isEnding = true;
    }
    
    bool search(string word) {
        TrieNode* parent = root;
        for(int i = 0; i<word.length(); i++){
            if(!parent->children.count(word[i])){
                return false;
            }
            parent = parent->children[word[i]];
        }
        return parent->isEnding;
    }
    
    bool startsWith(string prefix) {
        TrieNode* parent = root;
        for(int i = 0; i<prefix.length(); i++){
            if(!parent->children.count(prefix[i])){
                return false;
            }
            parent = parent->children[prefix[i]];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
class TrieNode {
public:
    int sum;
    unordered_map<char, TrieNode*> children;
    TrieNode() {
        sum = 0;
    }
};

class MapSum {
public:
    TrieNode* root;
    unordered_map<string,int> words;
    MapSum() { 
        root = new TrieNode(); 
    }

    void insert(string word, int value) {
        int val = value;
        if(words.count(word)){
            val-= words[word];
            words[word] = value;
        }else{
            words[word] = val;
        }
        TrieNode* parent = root;
        for (int i = 0; i < word.length(); i++) {
            if (!parent->children.count(word[i])) {
                parent->children[word[i]] = new TrieNode();
            }
            parent->sum+= val;
            parent = parent->children[word[i]];
        }
        parent->sum += val;
    }

    int sum(string word) {
        TrieNode* parent = root;
        for (int i = 0; i < word.length(); i++) {
            if (!parent->children.count(word[i])) {
                return 0;
            }
            parent = parent->children[word[i]];
        }
        return parent->sum;
    }
};

/**
 * Your MapSum object will be instantiated and called as such:
 * MapSum* obj = new MapSum();
 * obj->insert(key,val);
 * int param_2 = obj->sum(prefix);
 */
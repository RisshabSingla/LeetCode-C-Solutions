class TrieNode{
public:
    bool isEnding;
    unordered_map<int, TrieNode*> children;
    TrieNode(){
        isEnding = false;
    }
};

class Solution {
public:
    void insertWord(TrieNode* root, string& str) {
        TrieNode* parent = root;
        for (int i = 0; i < str.length(); i++) {
            if (!parent->children.count(str[i])) {
                parent->children[str[i]] = new TrieNode();
            }
            parent = parent->children[str[i]];
        }
        parent->isEnding = true;
    }
    vector<string> splitString(string& str){
        int front = 0;
        vector<string> arr;
        int slen = str.length();
        for(int i = 0; i<slen; i++){
            if(str[i] == ' '){
                arr.push_back(str.substr(front, i-front));
                front = i+1;
            }
        }
        arr.push_back(str.substr(front, slen-front));
        return arr;
    }
    string combineVectorString(vector<string>&words){
        string ans = "";
        for(auto &i: words){
            ans+= i;
            ans+= ' ';
        }
        return ans.substr(0, ans.length()-1);
    }
    string findRoot(string str, TrieNode* root){
        TrieNode* parent = root;
        int i;
        bool broken = false;
        for(i = 0;i<str.length(); i++){
            if (parent->children.count(str[i])) {
                parent = parent->children[str[i]];
                if(parent->isEnding){
                    broken = true;
                    break;
                }
            }else{
                break;
            }
        }
        if(broken){
            return str.substr(0, i+1);
        }
        return "";
    }
    void changeWords(vector<string>&words, TrieNode* parent){
        for(auto &i: words){
            string str = findRoot(i, parent);
            // cout<<"Str is: "<<str<<"\n";
            if(str != ""){
                i = str;
            }
        }
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode* root = new TrieNode();
        for(auto i: dictionary){
            insertWord(root, i);
        }
        vector<string> words = splitString(sentence);
        
        changeWords(words, root);

        return combineVectorString(words);
        // for(auto &i: words){
        //     cout<<i<<"\n";
        // }
    }
};
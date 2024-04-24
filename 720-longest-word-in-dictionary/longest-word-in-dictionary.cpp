class TrieNode{
public:
    bool isEnding;
    unordered_map<char, TrieNode*> children;
    TrieNode(){
        isEnding = false;
    }
};

class Solution {
public:
    string ans = "";
    void insert(TrieNode*root, string &word) {
        TrieNode* parent = root;
        for(int i = 0; i<word.length(); i++){
            if(!parent->children.count(word[i])){
                parent->children[word[i]] = new TrieNode();
            }
            parent = parent->children[word[i]];
        }
        parent->isEnding = true;
    }
    void dfs(TrieNode* root, string&str){
        // cout<<"String is: "<<str<<"\n";
        if(ans == ""){
            ans = str;
        }
        if(ans.length () < str.length()){
            ans = str;
        }
        if(ans.length() == str.length() && str < ans){
            ans = str;
        }
        for(auto &i : root->children){
            if(i.second->isEnding){
                str.push_back(i.first);
                dfs(i.second, str);
                str.pop_back();
            }
        }
    }

    string longestWord(vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(auto &i: words){
            insert(root, i);
        }
        string curr = "";
        dfs(root, curr);
        return ans;
    }
};
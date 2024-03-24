class TrieNode{
    public:
    int val;
    int index;
    int length;
    unordered_map<int,TrieNode*> children;
    // vector<TrieNode*> children;
    TrieNode(){
        val = -1;
        index = INT_MAX;
        length = INT_MAX;
        // children.resize(26, NULL);
    }
};

class Solution {
public:
    void printTrie(TrieNode* root){
        queue<TrieNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TrieNode* node = q.front();
            q.pop();
            if(!node){
                if(!q.empty()){
                    q.push(NULL);
                }
                cout<<"\n";
                continue;
            }
            cout<<char(node->val)<<" ";
            // for(int i = 0; i<26; i++){
            //     if(node->children[i] != NULL){
            //         q.push(node->children[i]);
            //     }
            // }
        }
    }
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery) {
        TrieNode* root = new TrieNode();
        int min_index = -1;
        int min_length = INT_MAX;
        for(int index = 0; index < wordsContainer.size(); index++){
            string str = wordsContainer[index];
            TrieNode* parent = root;
            if(str.length() < min_length){
                min_length = str.length();
                min_index = index;
            }
            for(int i = str.length()-1; i>=0; i--){
                
                if(parent->children.count(str[i]-'a')){
                    parent = parent->children[str[i]-'a'];
                }else{
                    parent->children[str[i]-'a'] = new TrieNode();
                    parent->children[str[i]-'a']->val = str[i];
                    parent = parent->children[str[i]-'a'];
                }
                if(parent->length > str.length()){
                    parent->length = str.length();
                    parent->index = index;
                }
            }
        }
        // printTrie(root);
        int n = wordsQuery.size();
        vector<int> ans(n , 0);
        for(int a = 0; a<n; a++){
            string str = wordsQuery[a];
            TrieNode* parent = root;
            // int index = INT_MAX;
            for(int i = str.length()-1; i>=0; i--){
                if(!parent->children.count(str[i]-'a')){
                    break;
                }else{
                    parent = parent->children[str[i]-'a'];
                }
                // index = min(index, parent->index);
            }
            // cout<<"for i: "<<i<<" index:"<<index<<"\n";
            // int ans_index = 0;
            // int ans_len = INT_MAX;
            // if(index == INT_MAX){
            //     ans[a] = min_index;
            // }else{
                // for(auto &i: index){
                //      int len = wordsContainer[i].length();
                //     if(len < ans_len){
                //         ans_len = len;
                //         ans_index = i;
                //     }
                // }
                // ans[a] = index;
            // }
            ans[a] = parent->index;
            if(ans[a] == INT_MAX){
                ans[a] = min_index;
            }
        }
        return ans;
        
    }
};
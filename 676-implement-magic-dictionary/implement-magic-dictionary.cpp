class MagicDictionary {
public:
    vector<string> words;
    int n;
    MagicDictionary() {
        n = 0;
    }
    
    void buildDict(vector<string> arr) {
        for(auto&i: arr){
            words.push_back(i);
        }
        n+= arr.size();
    }

    bool findDistance(string&str1, string&str2){
        int slen1 = str1.length();
        int slen2 = str2.length();
        if( slen1!= slen2){
            return 0;
        }
        int diff = 0;
        for(int i = 0; i<slen1; i++){
            if(str1[i] != str2[i]){
                diff++;
            }
            if(diff > 1){
                return false;
            }
        }
        return diff == 1;
    }

    bool search(string searchWord) {
        for(int i = 0; i<n; i++){
            if(findDistance(searchWord, words[i])){
                return true;
            }
        }
        return false;
    }
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dictionary);
 * bool param_2 = obj->search(searchWord);
 */
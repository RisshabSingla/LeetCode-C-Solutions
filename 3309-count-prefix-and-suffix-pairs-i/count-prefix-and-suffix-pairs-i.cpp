class Solution {
public:
    bool isPrefix(string &str1, string &str2){
        int n = str1.length();
        int m = str2.length();
        if(m < n){
            return false;
        }
        for(int i = 0; i<n; i++){
            if(str1[i] != str2[i]){
                return false;
            }
        }
        return true;
    }
    bool isSuffix(string &str1, string &str2){
        int n = str1.length();
        int m = str2.length();
        if(m < n){
            return false;
        }
        int index = m-1;
        for(int i = n-1; i>=0; i--){
            if(str1[i] != str2[index]){
                return false;
            }
            index--;
        }
        // cout<<"Returning true\n";
        return true;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n= words.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if(isPrefix(words[i], words[j]) && isSuffix(words[i], words[j])){
                    count++;
                }
            }
        }
        return count;
    }
};
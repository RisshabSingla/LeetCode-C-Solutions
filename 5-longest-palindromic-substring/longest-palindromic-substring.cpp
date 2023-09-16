class Solution {
public:
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start]!= s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int slen = s.length();
        if(slen<=1){
            return s;
        }
        // Approach 1: Brute Force
        int max_length = 1;
        string ans = "";
        ans+= s[0];
        
        for(int i = 0; i<slen; i++){
            for(int j = i+max_length; j<slen; j++){
                if(isPalindrome(s, i, j)){
                    int len = j-i+1;
                    if(len> max_length){
                        max_length = len;
                        ans = s.substr(i, len);
                    }
                    // max_length = max(max_length, j-i);
                }
            }
        }
        return ans;
    }
};
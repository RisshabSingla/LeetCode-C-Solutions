class Solution {
public:
    bool isPalindrome(string &str, int start,int end){
        while(start<end){
            if(str[start] != str[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int countSubstrings(string s) {
        int count = 0;
        int slen = s.length();
        for(int i = 0; i<slen;i++){
            for(int j = i; j<slen; j++){
                if(isPalindrome(s, i,j)){
                    count++;
                }
            }
        }
        return count;
    }
};
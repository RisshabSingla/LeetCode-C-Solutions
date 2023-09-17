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

    int expand(string &s, int left, int right, int &slen){
        int count = 0;
        while(left>=0 && right<slen){
            if(s[left]!= s[right]){
                break;
            }
            count++;
            left--;
            right++;
        }
        return count;
    }

    int countSubstrings(string s) {
        // Approach 1: Brute Force: O(n^3)
        // int slen = s.length();
        // int count = slen;
        // for(int i = 0; i<slen;i++){
        //     for(int j = i+1; j<slen; j++){
        //         if(isPalindrome(s, i,j)){
        //             count++;
        //         }
        //     }
        // }
        // return count;


        // Approach 2: Using Expanding approach
        int slen = s.length();
        int count = 0;
        for(int i = 0; i<slen; i++){
            count+= expand(s, i, i,slen);
            count+= expand(s, i, i+1,slen);
        }
        return count;
    }
};
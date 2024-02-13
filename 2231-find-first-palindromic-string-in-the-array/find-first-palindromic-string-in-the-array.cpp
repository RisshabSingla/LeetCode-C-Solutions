class Solution {
public:
    bool isPalindrome(string&str){
        int front = 0;
        int end = str.length()-1;
        while(front<end){
            if(str[front] != str[end]){
                return false;
            }
            front++;
            end--;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        int n = words.size();
        for(int i = 0; i<n; i++){
            if(isPalindrome(words[i])){
                return words[i];
            }
        }
        return "";
    }
};
class Solution {
public:
    bool isPalindrome(string str1){
        int front = 0;
        int back = str1.length()-1;
        while(front < back){
            if(str1[front] != str1[back]){
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
    int calcProducts(string&str, string str1, string str2, int index, int&slen){
        if(index == slen){
            if(isPalindrome(str1) && isPalindrome(str2)){
                return str1.length() * str2.length();
            }
            return 0;
        }
        int a = calcProducts(str, str1+str[index], str2, index+1, slen);
        int b = calcProducts(str, str1, str2+str[index], index+1, slen);
        int c = calcProducts(str, str1, str2, index+1, slen);
        return max({a,b,c});
    }
    int maxProduct(string s) {
        int slen = s.length();
        int prod = calcProducts(s, "","", 0, slen);
        return prod;
    }
};
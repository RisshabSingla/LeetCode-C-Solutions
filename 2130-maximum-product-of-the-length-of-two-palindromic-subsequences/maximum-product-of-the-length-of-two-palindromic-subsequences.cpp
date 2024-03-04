class Solution {
public:
    bool isPalindrome(string &str1){
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
    int calcProducts(string&str, string &str1, string &str2, int index, int&slen){
        if(index == slen){
            if(isPalindrome(str1) && isPalindrome(str2)){
                return str1.length() * str2.length();
            }
            return 0;
        }
        str1.push_back(str[index]);
        int a = calcProducts(str, str1, str2, index+1, slen);
        str1.pop_back();
        str2.push_back(str[index]);
        int b = calcProducts(str, str1, str2, index+1, slen);
        str2.pop_back();
        int c = calcProducts(str, str1, str2, index+1, slen);
        return max({a,b,c});
    }
    int maxProduct(string s) {
        int slen = s.length();
        string str1 = "";
        string str2 = "";
        return calcProducts(s, str1,str2, 0, slen);
    }
};
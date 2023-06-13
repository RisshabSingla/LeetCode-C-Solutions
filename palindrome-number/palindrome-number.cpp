class Solution {
public:
    bool isPalindrome(int x) {
        if(x <0){
            return false;
        }
        long long rev = 0;
        int a = x;
        while(a>0){
            int l = a%10;
            rev = rev*10 + l;
            a = a/10;
        }

        if(rev == x){
            return true;
        }
        return false;
    }
};
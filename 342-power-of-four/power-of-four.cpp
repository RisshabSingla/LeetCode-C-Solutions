class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1){
            return true;
        }
        if(n<=0){
            return false;
        }
        int l = log(n)/log(4);
        if(pow(4,l) == n || pow(4,(l+1)) == n){
            return true;
        }
        return false;

    }
};
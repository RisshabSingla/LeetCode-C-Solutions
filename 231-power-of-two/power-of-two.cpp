class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 0){
            return false;
        }
        // bool neg = false;
        if(n <0){
            return false;
        }
        int l = log(n)/log(2);
        long minus = pow(2,l-1);
        long equal = pow(2,l);
        long nxt = pow(2,l+1);
        // cout<<"Minus is: "<<minus<<endl;
        // cout<<"Equal is: "<<equal<<endl;
        // cout<<"Next is: "<<nxt<<endl;

        if(minus == n || equal == n || nxt == n){
            return true;
        }

        return false;
    }
};
class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.00;
        if(x== 1 || n == 0){
            return 1;
        }else if(n<0){
            x = 1/x;
            n = abs(n);
        }
        ans = ans*x;
        n--;
        int t = 0;
        while(n){
            t++;
            if(t<n){
                ans *= ans;
                n -= t;
                t += t;
            }
            if(n>0){
                ans *= x;
                n--;
            }
        }

        return ans;
    }
};
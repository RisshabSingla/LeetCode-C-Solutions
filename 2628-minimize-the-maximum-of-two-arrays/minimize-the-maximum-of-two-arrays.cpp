class Solution {
public:
    int minimizeSet(long long d1, long long d2, long long c1, long long c2) {
        long long left = 1;
        long long right = INT_MAX;
        long long lcm = (d1*d2)/(__gcd(d1,d2));
        long long ans = INT_MAX;
        while(left <= right){
            long long mid = left + (right-left)/2;
            if(d1 == d2){
                long long numbers = mid - (mid/d1);
                if(numbers >= c1+c2){
                    ans = mid;
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                long long common = mid/lcm;
                long long count1 = (mid/d1)- common;
                long long count2 = (mid/d2) - common;
                long long available = mid- (count1 + count2 + common);
                long long num1 = c1 - min(c1, count2);
                long long num2 = c2 - min(c2, count1);
                if(num1+num2<= available){
                    ans  = mid;
                    right = mid-1;
                }else{
                    left = mid+1;
                }

            }
        }
        return ans;

    }
};
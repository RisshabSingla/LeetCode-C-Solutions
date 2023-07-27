class Solution {
public:

    bool isValid(long long val, vector<int>&batteries, int n){
        long long total = 0;
        for(int i = 0; i<batteries.size(); i++){
            total += min(val,1LL*batteries[i]);
        }
        return total>=val*n;
    }
    long long maxRunTime(int n, vector<int>& batteries) {
        
        long long front = 1;
        long long end = 0;
        for(int i = 0; i<batteries.size(); i++){
            end+=batteries[i];
        }
        end = end/n;
        long long ans = 1;
        while(front<=end){
            long long mid = front + (end-front)/2;
            if(isValid(mid, batteries, n)){
                front = mid+1;
                ans = mid;
            }else{
                end = mid-1;
            }
        }
        return ans;
    }
};
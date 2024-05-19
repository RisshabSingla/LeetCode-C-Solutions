typedef long long ll;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        ll sum = 0;
        ll count = 0;
        ll smallest = INT_MAX;
        for(auto i: nums){
            if((i xor k) > i){
                sum+= (i xor k);
                count++;
                smallest = min(smallest, ll(i xor k) - i);
            }else{
                sum+= i;
                smallest = min(smallest, i- ll(i xor k));
            }
        }
        if(count % 2){
            return sum-smallest;
        }
        return sum;
    }
};
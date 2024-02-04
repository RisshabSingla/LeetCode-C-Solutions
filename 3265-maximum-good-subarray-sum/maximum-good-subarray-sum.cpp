class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            mp[nums[i]].push_back(i);
        }
        vector<long long> prefix(n,0);
        prefix[0] = nums[0];
        for(int i = 1; i<n; i++){
            prefix[i] = prefix[i-1]+nums[i];
        }
        long long max_sum = LLONG_MIN;
        for(int i = 0; i<n; i++){
            int a = nums[i] - k;
            int b = nums[i] + k;
            if(mp.count(a)){
                for(auto &j : mp[a]){
                    if(j < i){
                        continue;
                    }
                    long long sum =  prefix[j] - prefix[i] + nums[i];
                // cout<<"a is: "<<a<<" Sum is: "<<sum<<"\n";
                max_sum = max(max_sum, sum);
                }
               
            }
            if(mp.count(b) ){
                for(auto &j : mp[b]){
                    if(j < i){
                        continue;
                    }
                    long long sum =  prefix[j] - prefix[i] + nums[i];
                // cout<<"b is: "<<b<<" Sum is: "<<sum<<"\n";
                max_sum = max(max_sum, sum);
                }
            }
        }
        // cout<<"Ans is: "<<max_sum<<"\n";
        if(max_sum == LLONG_MIN){
            return 0;
        }
        return max_sum;
    }
};
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        
        // Approach 1: Brute Force -> O(n^3)
        
        
        // Approach 2: Optimized using Prefix Sum -> O(n^2)
        // int size = nums.size();
        // vector<int> sum(size,0);
        // sum[0] = nums[0];
        // for(int i = 1; i<size; i++){
        //     sum[i] = sum[i-1] + nums[i];
        // }
        // int count = 0;
        // for(int i = 0; i<size; i++){
        //     if(nums[i]%k == 0){
        //         // single subarray
        //         count++;
        //     }
        //     for(int j = size-1; j>i; j--){
        //         int s = sum[j] - sum[i] + nums[i];
        //         if(s%k == 0){
        //             count++;
        //         }
        //     }
        // }
        // return count;


        // Approach 3: Optimized by using remainder 
        int size = nums.size();
        unordered_map<int,int> mapping;
        mapping[0] = 1;
        int count = 0;
        int sum = 0;
        int rem = 0;
        for(int i = 0; i<size; i++){
            sum+= nums[i];
            int rem = sum % k;
            if(rem < 0){
                rem+= k;
            }
            if(mapping.count(rem) == 0){
                mapping[rem] = 1;
            }else{
                count+= mapping[rem];
                mapping[rem]++;
            }
        }
        return count;



    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int curr = 0;
        for(auto &i: nums){
            curr = curr xor i;
        }
        // for(int i = 0; i<nums.size(); i++){
        //     curr = curr xor nums[i];
        // }
        if(curr == k){
            return 0;
        }
        // int count = curr xor k;
        return __builtin_popcount(curr xor k);
        // int set = 0;
        // while(count){
        //     if(count % 2 == 1){
        //         set++;
        //     }
        //     count/=2;
        // }
        // return set;
    }
};
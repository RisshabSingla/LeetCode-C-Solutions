class Solution {
public:
    int singleNumber(vector<int>& nums) {
        // Approach 1: Maps
        // unordered_map<int,int> freq;
        // for(auto i : nums){
        //     freq[i]++;
        // }
        // for(auto i : freq){
        //     if(i.second == 1){
        //         return i.first;
        //     }
        // }

        // Approach 2: Sorting

        // sort(nums.begin(), nums.end());
        // int size = nums.size();
        // // if the element is at first index
        // if(nums[0]!= nums[1]){
        //     return nums[0];
        // }
        // // if the element is at the last index
        // if(nums[size-2]!= nums[size-1]){
        //     return nums[size-1];
        // }

        // for(int i = 1; i<size; i+=3){
        //     if(nums[i]!= nums[i-1]){
        //         return nums[i];
        //     }
        // }

        // Approach 3: Counting Set Bits in binary representation

        long long ans = 0;
        int size = nums.size();
        for(int i =0; i<32; i++){
            long long bit = 1LL<<i;
            int count = 0;
            for(int j = 0; j<size; j++){
                if(nums[j] & bit ){
                    count++;
                }
            }
            if(count%3 != 0){
                ans += bit;
            }
        }
        return (int)ans;



        // Approach 4: Bit Manipulation


        return 0;

    }
};
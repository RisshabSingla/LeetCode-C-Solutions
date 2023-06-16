class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        // sort(nums.begin(), nums.end());
        // int size = nums.size();
        // for(int i = 0; i<size-1; i++){
        //     if(nums[i] == nums[i+1]){
        //         return nums[i];
        //     }
        // }
        // return 0;
        unordered_map<int,int> freq;
        int size = nums.size();
        for(int i = 0; i<size; i++){
            if(freq.count(nums[i]) > 0 ){
                return nums[i];
            }
            freq[nums[i]]++;
        }
        return 0;
    }
};
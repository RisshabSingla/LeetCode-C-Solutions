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
        // unordered_map<int,int> freq;
        // int size = nums.size();
        // for(int i = 0; i<size; i++){
        //     if(freq.count(nums[i]) > 0 ){
        //         return nums[i];
        //     }
        //     freq[nums[i]]++;
        // }
        int n = nums.size();
        vector<int> arr(n + 1, 0);
        for (int i = 0; i < n; i++) {
            if(arr[nums[i]]){
                return nums[i];
            }
            arr[nums[i]] = 1;
        }
        return 0;
    }
};
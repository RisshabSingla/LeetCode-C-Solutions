class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            int k = 0;
            for( k = 0; k<m && i+k+1 < n; k++){
                if(pattern[k] == 0){
                    if(nums[i+k+1] != nums[i+k]){
                        break;
                    }
                }else if(pattern[k] == 1){
                    if(nums[i + k + 1] <= nums[i + k]){
                        break;
                    }
                }else{
                    if(nums[i + k + 1] >= nums[i + k]){
                        break;
                    }
                }
            }
            if(k == m){
                count++;
            }
        }
        return count;
    }
};
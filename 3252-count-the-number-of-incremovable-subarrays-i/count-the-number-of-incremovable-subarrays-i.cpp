class Solution {
public:
    bool isValid(vector<int>& nums, int start, int end, int n){
        vector<int> copy;
        
        
        for(int i = 0; i<start; i++){
            copy.push_back(nums[i]);
        }
        for(int i = end+1; i<n; i++){
            copy.push_back(nums[i]);
        }
        for(int i = 1; i<copy.size(); i++){
            if(copy[i-1] >= copy[i]){
                return false;
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for(int i = 0; i<n; i++){
            for(int j = i; j<n; j++){
                if(isValid(nums, i,j,n)){
                    count++;
                }
            }
        }
        return count;
    }
};
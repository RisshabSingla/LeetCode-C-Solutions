class Solution {
public:
    bool helper(vector<int>&nums, vector<int> &dp, int index, int size){
        if(index>=size){
            return true;
        }
        if(dp[index] != -1){
            return dp[index];
        }


        // same 2 elements
        if(index+1<size && nums[index]== nums[index+1]){
            dp[index] = helper(nums, dp, index+2, size);
            if(dp[index]){
                return true;
            }
        }

        // same 3 elements
        if(index+2<size && nums[index] == nums[index+1] && nums[index+1] == nums[index+2]){
            dp[index] = helper(nums, dp, index+3, size);
            if(dp[index]){
                return true;
            }
        }

        
        // consecutive 3 elements
        if(index+2<size && nums[index]+1 == nums[index+1] && nums[index+1]+1 == nums[index+2]){
            dp[index] = helper(nums, dp, index+3, size);
            if(dp[index]){
                return true;
            }
        }
        dp[index] = false;
        return false;
    }
    bool validPartition(vector<int>& nums) {
        
        int size = nums.size();
        vector<int> dp(size, -1);
        // helper(nums, 0, dp);
        return helper(nums, dp, 0, size);
    }
};
class Solution {
public:
    void helperRec(int index, vector<int>&nums, int &ans,  int curr, bool canRob){
        if(index == nums.size()){
            ans = max(ans, curr);
            return;
        }

        if(canRob){
            helperRec(index+1, nums, ans, curr+nums[index], false);
            // robbing the current house
            helperRec(index+1, nums, ans, curr, true);
            // not robbing the current house
        }else{
            helperRec(index+1, nums, ans, curr, true);
        }
    }


    int helperDP(vector<int>&nums){
        int size = nums.size();
        vector<vector<int>> dp(2, vector<int>(size, 0));

        dp[0][0] = nums[0];
        // robbing the first house

        for(int i = 1; i<size; i++){
            // canRob
            dp[0][i] = max(dp[1][i-1] + nums[i], dp[0][i-1]);

            // cannotRob
            dp[1][i] = max(dp[1][i-1], dp[0][i-1]);
        }
        return max(dp[0][size-1], dp[1][size-1]);
    }

    int rob(vector<int>& nums) {
        // int ans = 0;
        // helperRec(0,nums, ans, 0, true);
        // return ans;


        return helperDP(nums);

    }
};
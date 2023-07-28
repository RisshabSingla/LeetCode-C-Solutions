class Solution {
public: 

    int solveMemo(vector<int>&nums, int i, int j, bool choose, vector<vector<int>> &dp){
        if(i>j){
            return 0;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        int ans = 0;
        if(choose){
            int ans1 = nums[i] + solve(nums,i+1, j, false);
            int ans2 = nums[j] + solve(nums,i,j-1, false);
            ans = max(ans1, ans2);
        }else{
            int ans1 = -nums[i] + solve(nums, i+1, j, true);
            int ans2 = -nums[j] + solve(nums, i, j-1, true);
            ans = min(ans1, ans2);
        }
        dp[i][j] = ans;
        return ans;
    }
    
    int solve(vector<int>&nums, int i, int j, bool choose){
        if(i>j){
            return 0;
        }
        int ans = 0;
        if(choose){
            int ans1 = nums[i] + solve(nums,i+1, j, false);
            int ans2 = nums[j] + solve(nums,i,j-1, false);
            ans = max(ans1, ans2);
        }else{
            int ans1 = -nums[i] + solve(nums, i+1, j, true);
            int ans2 = -nums[j] + solve(nums, i, j-1, true);
            ans = min(ans1, ans2);
        }
        return ans;
    }

    bool PredictTheWinner(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>>dp(size, vector<int>(size, -1));
        int score = solveMemo(nums,0,size-1, true, dp);
        // int score = solve(nums,0,size-1, true);
        if(score>=0){
            return true;
        }
        return false;
    }
};
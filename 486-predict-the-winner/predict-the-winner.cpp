class Solution {
public: 
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
        bool choose = true;
        int size = nums.size();
        int score = solve(nums,0,size-1, choose);
        if(score>=0){
            return true;
        }
        return false;
    }
};
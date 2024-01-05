class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int size = nums.size();
        vector<int> dp(size+1, 1);
        for(int i = 1; i<size; i++){
            for(int j = i-1; j>=0; j--){
                if(nums[j]<nums[i]){
                    dp[i] = max(dp[i], dp[j]+1);
                }
            }
        }
        int longest = 0;
        for(int i = 0; i<=size; i++){
            longest = max(longest, dp[i]);
        }
        return longest;
    }
};
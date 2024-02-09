class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size(); 
        if(n == 0){
            return ans;
        }
        sort(nums.begin(), nums.end());
        vector<int>dp(n+1, 1);
        int maxi = 1;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 && dp[j] + 1> dp[i]){
                    dp[i] = dp[j] + 1;
                    maxi = max(maxi, dp[i]);
                }
            }
        }
        int prev = -1;
        for(int i = n-1; i>=0; i--){
            if(dp[i] == maxi && (prev%nums[i] == 0 || prev == -1)){
                ans.push_back(nums[i]);
                maxi--;
                prev = nums[i];
            }
        }
        return ans;
    }
};
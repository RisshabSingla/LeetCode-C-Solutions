class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        prefix[0] = nums[0];
        suffix[n-1] = nums[n-1];
        for(int i = 1; i<n; i++){
            prefix[i] = max(prefix[i-1], nums[i]);
            suffix[n-i-1] = max(suffix[n-i], nums[n-i-1]);
        }

        long long ans = 0;
        for(int i = 1; i<n-1; i++){
            long long a = ((long long)(prefix[i-1] - nums[i]))*suffix[i+1];
            ans = max(a, ans);
        }
        return ans;
    }
};
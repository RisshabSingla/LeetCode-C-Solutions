class Solution {
public:
    static bool comp(vector<int>& a, vector<int>& b) {
        if (a[0] == b[0]) {
            return a[1] > b[1];
        }
        return a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& arr) {

        // Approach 1: Using LIS
        // int n = arr.size();
        // if(n < 2){
        //     return n;
        // }
        // sort(arr.begin(), arr.end());
        // vector<int> dp(n+1,1);
        // int maxi = 1;
        // for(int i = 1; i<n; i++){
        //     for(int j = 0; j<i; j++){
        //         if(arr[i][0] > arr[j][0] && arr[i][1] > arr[j][1] && dp[i] <
        //         1+ dp[j]){
        //             dp[i] = 1+dp[j];
        //             maxi = max(dp[i], maxi);
        //         }
        //     }
        // }
        // return maxi;

        // Approach 2: Using Binary Search
        int n = arr.size();
        if (n < 2) {
            return n;
        }
        sort(arr.begin(), arr.end(), comp);
        vector<int> ans;
        ans.push_back(arr[0][1]);
        for (int i = 1; i < n; i++) {
            if (arr[i][1] > ans.back()) {
                ans.push_back(arr[i][1]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i][1]) -
                            ans.begin();
                ans[index] = arr[i][1];
            }
        }
        return ans.size();
    }
};
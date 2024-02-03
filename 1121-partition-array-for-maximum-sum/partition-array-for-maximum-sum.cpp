class Solution {
public:
    int dp[501];
    // int recursion(vector<int>&arr, int index, int&n, int& k){
    //     if(index >= n){
    //         return 0;
    //     }
    //     int maxi = 0;
    //     int maxVal = 0;
    //     for(int j = index; j<min(n, index+k); j++){
    //         maxVal = max(arr[j], maxVal);
    //         maxi = max(maxi, (j-index+1)*maxVal + recursion(arr,j+1, n, k));
    //     }
    //     return maxi;
    // }
    int memo(vector<int>&arr, int index, int&n, int& k){
        if(index >= n){
            return 0;
        }
        if(dp[index] != -1){
            return dp[index];
        }
        int maxi = 0;
        int maxVal = 0;
        for(int j = index; j<min(n, index+k); j++){
            maxVal = max(arr[j], maxVal);
            maxi = max(maxi, (j-index+1)*maxVal + memo(arr,j+1, n, k));
        }
        return dp[index] = maxi;
    }


    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(dp, -1, sizeof(dp));
        int n = arr.size();
        return memo(arr, 0, n, k);
    }
};
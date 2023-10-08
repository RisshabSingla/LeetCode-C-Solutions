class Solution {
public:
    // int dp[501][501];
    // int recursive(vector<int>& nums1, vector<int>& nums2, int index1, int index2, int n, int m){
    //     if(index1 == n || index2 == m){
    //         return INT_MIN;
    //     }
    //     int a = recursive(nums1, nums2, index1+1, index2+1, n,m);
    //     if(a == INT_MIN){
    //         a = nums1[index1]*nums2[index2];
    //     }else{
    //         a+= nums1[index1]*nums2[index2];
    //     }
    //     int b = recursive(nums1, nums2, index1+1, index2, n,m);
    //     int c = recursive(nums1, nums2, index1, index2+1, n,m);
    //     return max({a,b,c});
    // }

    // int memo(vector<int>& nums1, vector<int>& nums2, int index1, int index2, int n, int m){
    //     if(index1 == n || index2 == m){
    //         return INT_MIN;
    //     }
    //     if(dp[index1][index2] != INT_MIN){
    //         return dp[index1][index2];
    //     }
    //     int a = memo(nums1, nums2, index1+1, index2+1, n,m);
    //     if(a == INT_MIN){
    //         a = nums1[index1]*nums2[index2];
    //     }else{
    //         a+= nums1[index1]*nums2[index2];
    //     }
    //     int b = memo(nums1, nums2, index1+1, index2, n,m);
    //     int c = memo(nums1, nums2, index1, index2+1, n,m);
    //     dp[index1][index2] = max({a,b,c});
    //     return dp[index1][index2];
    // }

    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        // // return recursive(nums1, nums2, 0,0, n,m);
        // memset(dp, INT_MIN, sizeof(dp));
        // return memo(nums1,nums2, 0,0,n,m);
        vector<vector<int>> dp(n, vector<int>(m, INT_MIN));
        dp[0][0] = nums1[0]*nums2[0];
        for(int i = 1; i<n; i++){
            dp[i][0] = max(dp[i-1][0], nums1[i]*nums2[0]);
        }

        for(int j = 1; j<m; j++){
            dp[0][j] = max(dp[0][j-1], nums1[0]*nums2[j]);
        }

        for(int i = 1; i<n; i++){
            for(int j = 1; j<m;j++){
                dp[i][j] = max({dp[i-1][j], dp[i][j-1], dp[i-1][j-1] + nums1[i]*nums2[j], dp[i-1][j-1], nums1[i]*nums2[j]});
            }
        }
        // for(auto i: dp){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        return dp[n-1][m-1];

    }
};
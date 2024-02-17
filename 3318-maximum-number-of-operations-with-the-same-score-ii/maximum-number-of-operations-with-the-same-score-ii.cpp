class Solution {
public:
    int dp[2001][2001];
    int recursive(vector<int>& nums, int start, int end, int req_sum, int n){
        // cout<<"Start is: "<<start<<" end is: "<<end<<" req: "<<req_sum<<"\n";
        int size = end-start+1;
        if(size < 2){
            return 0;
        }
        if(dp[start][end] != -1){
            return dp[start][end];
        }
        int maxi = 0;
        if(start+1<n && start+1<end){
            int front2 = nums[start]+nums[start+1];
            if(front2 == req_sum){
                maxi = max(recursive(nums, start+2, end, req_sum,n) + 1, maxi);
            }
        }
        if(end-1>=0 && end-1>start){
            int end2 = nums[end]+nums[end-1];
            if(end2 == req_sum){
                maxi = max(recursive(nums, start, end-2, req_sum,n) + 1 ,maxi);
            }
        }
        if(nums[start] + nums[end] == req_sum){
            maxi = max(maxi, recursive(nums, start+1, end-1, req_sum,n) + 1);
        }
        // cout<<"Returning maxi: "<<maxi<<"\n";
        return  dp[start][end] =  maxi;
    }
    int maxOperations(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int n = nums.size();
        int front2 = recursive(nums, 2, n-1, nums[0]+nums[1],n);
        int end2 = recursive(nums, 0, n-3, nums[n-1]+nums[n-2],n);
        int tails = recursive(nums, 1, n-2, nums[0]+nums[n-1],n);
        return max({front2, end2, tails} ) + 1;
    }
};
class Solution {
public:
    int findLIS(vector<int> &nums, int n){
        vector<int> arr(n, 1);
        int maxi = 1;
        for(int i = 1; i<n; i++){
            for(int j = 0; j<i; j++){
                if(nums[i] >= nums[j] && arr[j]+1 >= arr[i]){
                    arr[i] = arr[j] + 1;
                    maxi = max(maxi, arr[i]);
                }
            }
        }
        return maxi;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return 0;
        }
        int longest = findLIS(nums , n);
        // cout<<"LIS: "<<longest<<"\n";
        return n - longest;
    }
};
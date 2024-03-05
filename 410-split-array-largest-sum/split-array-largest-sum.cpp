class Solution {
public:
    int calcSum(vector<int>&nums, int& k, int &max_sum, int&n ){
        int sum = 0;
        int count = 1;
        for(int i = 0; i<n; i++){
            sum+= nums[i];
            // if(nums[i] > max_sum){
            //     return INT_MAX;
            // }
            if(sum>max_sum){
                sum = nums[i];
                count++;
            }
        }
        return count;
    }
    int splitArray(vector<int>& nums, int k) {
        long long low = 0;
        long long high = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            low = max(low, (long long)(nums[i]));
            high+= (long long)nums[i];
        }
        while(low <=high){
            int mid = low + (high-low)/2;
            int count = calcSum(nums, k, mid, n);
            // if(count == k){
            //     ans = min(ans, mid); 
            // }
            if(count > k){
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        return low;
    }
};
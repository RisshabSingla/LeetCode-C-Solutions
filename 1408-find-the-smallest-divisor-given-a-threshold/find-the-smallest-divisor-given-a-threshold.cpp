class Solution {
public:
    bool isPossible(vector<int>&nums, int thres, int n, int div){
        int sum = 0;
        for(int i = 0; i<n; i++){
            sum+= nums[i]/div;
            if(nums[i]%div != 0){
                sum++;
            }
        }
        return sum<=thres;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1;
        int high = INT_MAX;
        int ans = 0;
        int n = nums.size();
        while(low<=high){
            int mid = low+(high-low)/2;
            if(isPossible(nums, threshold, n, mid)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
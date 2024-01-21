class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size() == 3){
            return nums[0]+nums[1]+nums[2];
        }
        int min_sum = INT_MAX;
        int n = nums.size();
        for(int i = 1; i<n-1; i++){
            for(int j = i+1; j<n; j++){
                int sum1= nums[0] ;
                int sum2= nums[i] ;
                int sum3= nums[j] ;
                min_sum = min((sum1+sum2+sum3), min_sum);
            }
        }
        return min_sum;
    }
};
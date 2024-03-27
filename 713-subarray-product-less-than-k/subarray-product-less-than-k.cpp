class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k == 0){
            return 0;
        }
        int count = 0;
        long long prod = 1;
        int front = 0;
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<nums.size(); i++){
            prod*= nums[i];
            count++;
            while(prod >= k && front <= i){
                prod /= nums[front];
                front++;
                count--;
            }
            if(prod == 0){
                prod = 1;
            }
            if(count < 0){
                count = 0;
            }
            ans+= count;
        }
        return ans;
    }
};
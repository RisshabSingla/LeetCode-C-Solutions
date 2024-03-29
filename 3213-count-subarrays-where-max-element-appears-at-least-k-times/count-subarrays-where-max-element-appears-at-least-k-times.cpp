class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_elem = *max_element(nums.begin(), nums.end());
        long long ans = 0;
        int end = 0;
        int count = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == max_elem){
                count++;
            }
            while(count >= k){
                ans+= (n-i);
                if(nums[end] == max_elem){
                    count--;
                }
                end++;
            }
        }
        return ans;

    }
};
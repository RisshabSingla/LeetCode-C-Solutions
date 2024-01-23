class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int start = 0;
        int end = 0;
        unordered_map<int,int> freq;
        int n = nums.size();
        int max_len = 0;
        while(start<=end && end< n){
            freq[nums[end]]++;
            if(freq[nums[end]] > k){
                max_len = max(max_len, end-start);
                while(freq[nums[end]] > k){
                    freq[nums[start]]--;
                    start++;
                }
            }
            end++;
        }
        max_len = max(max_len, end-start);
        return max_len;
    }
};
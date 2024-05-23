class Solution {
public:
    int helper(vector<int>& nums, int k, unordered_map<int, int>& freq, int i) {
        if (i == nums.size()) { 
            return 1;
        }
        int result = helper(nums, k, freq, i + 1); 
        if (!freq[nums[i] - k] && !freq[nums[i] + k]) { 
            freq[nums[i]]++;
            result += helper(nums, k, freq, i + 1);
            freq[nums[i]]--;
        }
        return result;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        return helper(nums, k, freq, 0) - 1;
    }
};
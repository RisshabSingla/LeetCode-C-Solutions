class Solution {
public:
    bool isValid(vector<int>& nums, int start, int end, int n) {
        int prev = 0;
        for (int i = 0; i < n; i++) {
            if (i >= start && i <= end) {
                continue;
            }
            if (nums[i] > prev) {
                prev = nums[i];
            } else {
                return false;
            }
        }
        return true;
    }
    int incremovableSubarrayCount(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                if (isValid(nums, i, j, n)) {
                    count++;
                }
            }
        }
        return count;
    }
};
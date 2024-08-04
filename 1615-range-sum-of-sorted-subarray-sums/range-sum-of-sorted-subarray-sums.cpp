class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> arr;
        int mod = 1e9 + 7;
        for (int i = 0; i < n; i++) {
            int sum = 0;
            for (int j = i; j < n; j++) {
                sum += nums[j];
                arr.push_back(sum);
            }
        }
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++) {
            arr[i] = (arr[i] + arr[i - 1]) % mod;
        }
        if (left == 1) {
            return arr[right - 1];
        }
        return arr[right - 1] - arr[left - 2];
    }
};
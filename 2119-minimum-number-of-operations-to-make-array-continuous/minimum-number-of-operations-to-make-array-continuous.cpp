class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> duplicate(n, 0);
        for(int i = 1; i < n; i++)
        {
            if(nums[i] == nums[i - 1])
            {
                duplicate[i] = duplicate[i - 1] + 1;
            }
            else
            {
                duplicate[i] = duplicate[i - 1];
            }
        }
        int ans = INT_MAX;
        for(int i = 0; i < n; i++)
        {
            int tmp = i;
            int s = nums[i] + n - 1;
            auto it = lower_bound(nums.begin(), nums.end(), s) - nums.begin();

            if(it == n)it--;
            if(nums[it] > s)it--;

            tmp += n - it - 1;
            tmp += duplicate[it] - duplicate[i];

            ans = min(tmp, ans);
        }

        return ans;
    }
};
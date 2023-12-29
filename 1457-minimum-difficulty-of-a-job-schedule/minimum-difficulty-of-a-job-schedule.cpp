class Solution {
public:
    int minDifficulty(vector<int>& arr, int d) {
        int n = arr.size();
        if (n < d) {
            return -1;
        } else if (n == d) {
            int totalDifficulty = 0;
            for (int difficulty : arr)
                totalDifficulty += difficulty;
            return totalDifficulty;
        }
        vector<int> dp(n);
        dp[0] = arr[0];

        for (int i = 1; i < n; ++i) {
            dp[i] = max(arr[i], dp[i - 1]);
        }

        vector<int> dpPrev(n);

        for (int i = 1; i < d; ++i) {
            dp.swap(dpPrev);
            for (int j = i; j < n; ++j) {
                int lastDayDifficulty = arr[j];
                int tmpMin = lastDayDifficulty + dpPrev[j - 1];
                for (int t = j - 1; i - 1 < t; --t) {
                    lastDayDifficulty = max(lastDayDifficulty, arr[t]);
                    tmpMin = min(tmpMin, lastDayDifficulty + dpPrev[t - 1]);
                }

                dp[j] = tmpMin;
            }
        }
        return dp.back();
    }
};
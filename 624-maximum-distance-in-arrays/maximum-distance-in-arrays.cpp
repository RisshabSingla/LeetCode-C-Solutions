class Solution {
public:
        int maxDistance(vector<vector<int>>& arrays) {
        int maxDiff = 0;
        int curMin = 1e5;
        int curMax = -1e5;
        for (auto& arr : arrays) {
            maxDiff = max(maxDiff, max(arr.back()-curMin, curMax-arr.front()));
            curMin = min(curMin, arr.front());
            curMax = max(curMax, arr.back());
        }
        return maxDiff;
    }
};
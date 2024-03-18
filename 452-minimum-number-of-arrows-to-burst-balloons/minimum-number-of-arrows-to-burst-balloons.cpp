class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int findMinArrowShots(vector<vector<int>>& arr) {
        sort(arr.begin(), arr.end(), cmp);
        int ans = 0;
        int lastPoint = 0;
        for (int i = 0; i < arr.size(); i ++) {
            if (ans == 0 || arr[i][0] > lastPoint) {
                ans ++;
                lastPoint = arr[i][1];
            }
        }
        return ans;
    }
};
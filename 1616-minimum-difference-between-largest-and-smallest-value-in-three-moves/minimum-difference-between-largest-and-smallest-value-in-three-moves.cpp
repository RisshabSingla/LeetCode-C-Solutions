class Solution {
public:
    int minDifference(vector<int>& arr) {
        int n = arr.size();
        if (n <= 4) {
            return 0;
        }
        sort(arr.begin(), arr.end());
        return min({arr[n - 1] - arr[3], arr[n - 2] - arr[2],
                    arr[n - 3] - arr[1], arr[n - 4] - arr[0]});
    }
};
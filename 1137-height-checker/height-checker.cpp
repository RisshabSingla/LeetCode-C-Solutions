class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> arr(heights.begin(), heights.end());
        sort(arr.begin(), arr.end());
        int ans = 0;
        for(int i = 0; i<arr.size();i++){
            if(heights[i] != arr[i]){
                ans++;
            }
        }
        return ans;
    }
};
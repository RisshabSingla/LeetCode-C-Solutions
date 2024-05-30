class Solution {
public:
    long long findSum(vector<int>& heights, int peak, int n){
        long long sum = heights[peak];
        int prev = heights[peak];
        for(int i = peak+1; i<n; i++){
            if(heights[i] <= prev){
                sum+= heights[i];
                prev = heights[i];
            }else{
                sum+= prev;
            }
        }
        prev = heights[peak];
        for(int i = peak-1; i>=0 ; i--){
            if(heights[i] <= prev){
                sum+= heights[i];
                prev = heights[i];
            }else{
                sum+= prev;
            }
        }
        return sum;
    }
    long long maximumSumOfHeights(vector<int>& heights) {
        long long sum = 0;
        int n = heights.size();
        for(int peak = 0; peak<n; peak++){
            long long possible = findSum(heights, peak, n);
            sum = max(sum, possible);
        }
        return sum;
    }
};
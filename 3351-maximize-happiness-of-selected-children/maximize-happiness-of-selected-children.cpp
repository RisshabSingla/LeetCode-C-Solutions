class Solution {
public:
    long long maximumHappinessSum(vector<int>& arr, int k) {
        long long count = 0;
        sort(arr.begin(), arr.end(), greater<int>());
        for(int i = 0; i<k; i++){
            count+= max((arr[i]-i),0);
        }
        return count;
    }
};
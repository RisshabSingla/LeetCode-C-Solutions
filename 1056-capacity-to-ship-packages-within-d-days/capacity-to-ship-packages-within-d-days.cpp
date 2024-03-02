class Solution {
public:
    bool isPossible(vector<int>&arr, int days, int maxi, int n){
        int count = 1;
        int sum = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] > maxi){
                return false;
            }
            sum+= arr[i];
            if(sum > maxi){
                sum = arr[i];
                count++;
            }
        }
        return count<=days;
    }
    int shipWithinDays(vector<int>& arr, int days) {
        int n = arr.size();
        int low = 0;
        int high = INT_MAX;
        int ans = 0;
        while(low<=high){
            int mid = low +(high-low)/2;
            if(isPossible(arr, days, mid, n)){
                high = mid-1;
                ans = mid;
            }else {
                low = mid+1;
            }
        }
        return ans;
    }
};
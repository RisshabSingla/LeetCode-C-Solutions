class Solution {
public:

    bool isPossible(vector<int> &arr, int m, int k, int day, int n){
        int count = 0;
        int front = 0;
        int end = 0;
        for(int i = 0; i<n; i++){
            if(arr[i] <= day){
                end++;
            }else{
                front = end;
            }
            if(end-front >= k){
                count++;
                front = end;
            }
        }
        return count>= m;
        
    }
    int minDays(vector<int>& arr, int m, int k) {
        long long total_req = (long long)(m)*k;
        long long n = arr.size();
        if(n < total_req){
            return -1;
        }
        int maxi = *max_element(arr.begin(), arr.end());
        if(n == total_req){
            return maxi;
        }

        int low = 1;
        int high = maxi+1;
        int ans = 0;
        while(low<= high){
            int mid = low + (high-low)/2;
            if(isPossible(arr, m ,k, mid, n)){
                high = mid-1;
                ans = mid;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};
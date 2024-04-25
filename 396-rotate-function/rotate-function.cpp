class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        // long long maxi = INT_MIN;
        // long long n = nums.size();
        // for(long long i = 0; i<n;i++){
        //     long long score = 0;
        //     for(long long j = 0; j<n; j++){
        //         score+= j*nums[(i+j)%n];
        //     }
        //     maxi = max(maxi, score);
        // }
        // return int(maxi);

        int sum = accumulate(nums.begin(), nums.end(), 0);
        int f0 = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            f0 += i*nums[i];
        }

        int maxi = f0;
        int prev = f0;
        for(int i = 1; i<n; i++){
            int fi = prev + sum - n*nums[n-i];
            prev = fi;
            maxi = max(maxi, fi);
        }
        return maxi;
    }
};
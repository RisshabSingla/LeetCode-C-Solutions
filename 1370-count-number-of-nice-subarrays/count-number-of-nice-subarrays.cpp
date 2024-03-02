class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // int n = nums.size();
        // vector<int> pref(n+1, 0);
        // for(int i = 1; i<=n; i++){
        //     pref[i] = pref[i-1];
        //     if(nums[i-1] % 2 ){
        //         pref[i]++;
        //     }
        // }
        // int ans = 0;
        // for(int i = 1; i<=n; i++){
        //     for(int j = i; j<=n; j++){
        //         int count = pref[j] - pref[i-1];
        //         if(count == k){
        //             ans++;
        //         }
        //     }
        // }

        int count = 0;
        int ans = 0;
        int n = nums.size();
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i = 0; i<n; i++){
            if(nums[i] % 2){
                count++;
            }
            if(mp.count(count-k)){
                ans+= mp[count-k];
            }
            mp[count]++;
        }
        return ans;
    }
};
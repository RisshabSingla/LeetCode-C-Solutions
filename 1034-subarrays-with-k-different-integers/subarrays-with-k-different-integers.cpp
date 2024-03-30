class Solution {
public:
    int check(vector<int>& nums, int k) {
        int count = 0;
        unordered_map<int, int> mp;
        int front = 0;
        int end = 0;
        int n = nums.size();
        while (end < n) {
            mp[nums[end]]++;
            while (mp.size() > k) {
                mp[nums[front]]--;
                if (mp[nums[front]] == 0) {
                    mp.erase(nums[front]);
                }
                front++;
            }
            count += (end - front + 1);
            end++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // unordered_map<int,int> mp;
        // int end = 0;
        // int n = nums.size();
        // int ans = 0;
        // for(int i = 0; i<n; i++){
        //     mp[nums[i]]++;
        //     int size = mp.size();
        //     if(size ==  k){
        //         ans++;
        //     }else
        //     if(size > k){
        //         while(size > k){
        //             mp[nums[end]]--;
        //             if(mp[nums[end]] == 0){
        //                 size--;
        //                 mp.erase(nums[end]);
        //             }
        //             ans++;
        //         }
        //     }
        // }
        // return ans;

        return check(nums, k) - check(nums, k-1);
    }
};
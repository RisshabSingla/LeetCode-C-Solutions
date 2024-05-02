class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int maxi = INT_MIN;
        unordered_map<int,int> mp;
        for(int i = 0; i<nums.size(); i++){
            mp[nums[i]]++;
            if(nums[i] < 0){
                if(mp.count(abs(nums[i]))){
                    maxi =max(maxi, abs(nums[i]));
                }
            }else{
                if(mp.count(-nums[i])){
                    maxi = max(maxi, nums[i]);
                }
            }
        }
        if(maxi == INT_MIN){
            return -1;
        }
        return maxi;
    }
};
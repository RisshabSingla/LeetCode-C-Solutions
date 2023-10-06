class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> mapping;
        int sum = 0;
        int count = 0;
        for(int i = 0; i<n;i++){
            sum+= nums[i];
            if(sum == k){
                count++;
            }
            if(mapping.count(sum-k)){
                count+= mapping[sum-k];
            }
            mapping[sum]++;
        }
        return count;
    }
};
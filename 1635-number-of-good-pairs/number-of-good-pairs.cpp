class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count = 0;
        unordered_map<int,int> freq;
        for(int i = 0; i<nums.size(); i++){
            if(freq.count(nums[i])){
                count+= freq[nums[i]];
                freq[nums[i]]++;
            }else{
                freq[nums[i]]++;
            }
        }
        return count;
    }
};
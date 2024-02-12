class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int length = nums.size();
        for(auto i: nums){
            freq[i]++;
        }
        int req = floor(length/2);
        for(auto i: freq){
            if(i.second > req){
                return i.first;
            }
        }
        return 0;
    }
};
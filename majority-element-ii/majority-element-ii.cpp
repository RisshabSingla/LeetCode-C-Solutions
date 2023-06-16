class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> freq;
        int size = nums.size();
        for(int i = 0; i<size; i++){
            freq[nums[i]]++;
        }
        int pivot = floor(size/3);
        vector<int> ans;
        for(auto i: freq){
            if(i.second >pivot){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};
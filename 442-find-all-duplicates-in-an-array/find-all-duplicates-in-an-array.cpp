class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int> present(n+1, 0);
        vector<int> ans;
        for(int i = 0; i<n; i++){
            present[nums[i]]++;
            if(present[nums[i]] == 2){
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};
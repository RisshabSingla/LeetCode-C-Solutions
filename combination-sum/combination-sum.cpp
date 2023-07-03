class Solution {
public:
    void helper(vector<int> &nums, int target, int index, vector<int> combination, vector<vector<int>> &ans, int size){

        // cout<<"Target is: "<target<<endl;
        // for(int i = 0; i<nums.size(), )


        if(target == 0){
            ans.push_back(combination);
            return;
        }

        if(target<0){
            return;
        }
        
        if(index == size){
            return;
        }

        // not including the current number
        helper(nums, target, index+1,combination, ans,size);

        // including the curr number
        combination.push_back(nums[index]);
        helper(nums, target-nums[index], index,combination, ans, size);

        
        // nums.pop_back();
    
    }


    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        // int size 
        vector<int> combination;
        helper(nums, target, 0, combination, ans, nums.size());
        return ans;
    }
};
class Solution {
public:
    void helper(vector<int> &nums, int index, int n ,
            vector<vector<int>> &ans ){
        if(index >= n){
            // cout<<"Pushing inside ans"<<endl;
            ans.push_back(nums);
            return;
        }

        // cout<<"Inside"<<endl;
        for(int i = index; i<n; i++){
            swap(nums[index], nums[i]);
            helper(nums, index+1, n, ans);
            swap(nums[index], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        // cout<<"Calling"<<endl;
        helper(nums, 0, nums.size() , ans);
        // cout<<"Returning"<<endl;
        return ans;
    }
};
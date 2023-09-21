class Solution {
public:
    void helper(vector<int> nums, int index, int n ,
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

    void helper2(vector<int> nums, int index, int n ,
            vector<vector<int>> &ans){    
            if(index >= n){
            ans.push_back(nums);
            return;
        }
        set<int> done;
        for(int i = index; i<n; i++){
            if(done.count(nums[i])){
                continue;
            }
            done.insert(nums[i]);
            swap(nums[index], nums[i]);
            helper2(nums, index+1, n, ans);
            swap(nums[index], nums[i]);
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // vector<vector<int>> ans;
        // // sort(nums.begin(), nums.end());
        // helper(nums, 0, nums.size() , ans);
        // // return ans;
        // set<vector<int>> unique;
        // for(auto i: ans){
        //     unique.insert(i);
        // }
        // vector<vector<int>> unique_ans;
        // for(auto i : unique){
        //     unique_ans.push_back(i);
        // }
        // return unique_ans;


        vector<vector<int>> ans;
        helper2(nums,0, nums.size(), ans);
        return ans;
    }
};
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


    void helper3(unordered_map<int,int> &mapping, vector<vector<int>> &ans, int index, int n, vector<int> &curr){
        if(index == n){
            ans.push_back(curr);
            return;
        }

        for(auto i: mapping){
            if(i.second == 0){
                continue;
            }
            curr.push_back(i.first);
            mapping[i.first]--;
            helper3(mapping, ans, index+1, n, curr);
            curr.pop_back();
            mapping[i.first]++;
        }
    }



    vector<vector<int>> permuteUnique(vector<int>& nums) {
        // Approach 1: All in set
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

        // Approach 2: Not using twice
        // vector<vector<int>> ans;
        // helper2(nums,0, nums.size(), ans);
        // return ans;


        // Approach 3: Hashmap
        vector<vector<int>> ans;
        unordered_map<int,int> mapping;
        for(int i = 0; i<nums.size(); i++){
            mapping[nums[i]]++;
        }
        vector<int> curr;
        helper3(mapping, ans,0, nums.size(), curr);
        return ans;
    }
};
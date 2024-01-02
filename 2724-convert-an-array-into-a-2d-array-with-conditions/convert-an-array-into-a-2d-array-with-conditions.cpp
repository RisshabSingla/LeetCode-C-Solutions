class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({nums[0]});
        unordered_map<int,int> mp;
        mp[nums[0]]++;
        for(int i =1; i<nums.size();i++){
            if(mp.count(nums[i]) == 0){
                ans[0].push_back(nums[i]);
            }else{
                int sz = ans.size();
                int occ = mp[nums[i]];
                if(sz == occ){
                    ans.push_back({nums[i]});
                }else{
                    ans[occ].push_back(nums[i]);
                }
            }
            mp[nums[i]]++;
            // for(auto i: ans){
            //     for(auto j: i){
            //         cout<<j<<" ";
            //     }
            //     cout<<"\n";
            // }
            // cout<<"\n";
        }
        return ans;
    }
};
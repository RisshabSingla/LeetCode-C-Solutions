class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> indexes;
        int n = queries.size();
        vector<int> ans(n, -1);
        for(int i = 0; i<nums.size(); i++){
            if(nums[i] == x){
                indexes.push_back(i);
            }
        }
        int size = indexes.size();
        for(int i=0; i<n;i++){
            if(queries[i]-1 < size){
                ans[i] = indexes[queries[i]-1];
            }
        }
        return ans;
    }
};
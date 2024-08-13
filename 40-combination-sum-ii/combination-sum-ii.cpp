class Solution {
public:
    void helper(vector<int>& candidates, int target, int index, int size, vector<vector<int>> &ans, vector<int> &combination){
        if(target == 0){
            ans.push_back(combination);
            return;
        }
        if(target<0){
            return;
        }

        for(int i = index; i<size; i++){
            if(i>index && candidates[i] == candidates[i-1]){
                continue;
            }
            if(target-candidates[i] <0){
                break;
            }
            combination.push_back(candidates[i]);
            helper(candidates, target-candidates[i],i+1, size, ans, combination);
            combination.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> ans;
        vector<int> combination;
        helper(candidates, target, 0, candidates.size(), ans, combination);
        return ans;
    }
};
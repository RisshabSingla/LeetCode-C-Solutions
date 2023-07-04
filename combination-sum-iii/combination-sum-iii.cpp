class Solution {
public:
    void helper(int k, int n, vector<vector<int>> &ans, vector<int> comb, int index){
        if(n<0){
            return;
        }
        if(k<0){
            return;
        }
        if(k == 0){
            if(n == 0){
                ans.push_back(comb);
            }
            return;
        }
        if(index > 9){
            return;
        }
        comb.push_back(index);
        helper(k-1, n - index,ans,comb, index+1);
        comb.pop_back();
        helper(k, n,ans,comb, index+1);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        helper(k,n, ans, comb,1);
        return ans;
    }
};
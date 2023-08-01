class Solution {
public:
    void helper(int num, int n, int k, vector<int>&arr,vector<vector<int>> &ans){
        
        if(k==0){
            ans.push_back(arr);
            return;
        }
        if(num > n){
            return;
        }
    
        // for(int i = num; i<=n; i++){
        //     arr.push_back(num);
        //     helper(i+1, n, k-1, arr, ans);
        //     arr.pop_back();
        // }

        // including the current number
        arr.push_back(num);
        helper(num+1, n, k-1, arr, ans);
        arr.pop_back();
        helper(num+1, n,k, arr, ans);
    }
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> arr;
        helper(1, n,k, arr,ans);
        return ans;
    }
};
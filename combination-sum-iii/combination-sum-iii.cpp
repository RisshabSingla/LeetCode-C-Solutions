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


    void helper(int k, int n, vector<vector<int>> &ans, vector<int> comb, vector<int> visited, int start){
        if(k==0){
            if(n==0){
                ans.push_back(comb);
            }
            return;
        }
        if(k<0 || n<0){
            return;
        }

        for(int i = start; i<10; i++){
            if(visited[i] == 0){
                visited[i] = 1;
                comb.push_back(i);
                helper(k-1, n-i, ans, comb, visited, i+1);
                visited[i] = 0;
                comb.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> comb;
        // helper(k,n, ans, comb,1);

        vector<int> visited(10,0);
        helper(k,n, ans, comb,visited,1);
        return ans;
    }
};
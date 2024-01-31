class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans(n,0);
        stack<pair<int,int>> stk;
        stk.push({arr[n-1], n-1});
        for(int i= n-2; i>=0; i--){ 
            while(!stk.empty() && stk.top().first <= arr[i]){
                stk.pop();
            }
            if(!stk.empty()){
                ans[i] = stk.top().second-i;
            }
            stk.push({arr[i],i});
        }
        return ans;
    }
};
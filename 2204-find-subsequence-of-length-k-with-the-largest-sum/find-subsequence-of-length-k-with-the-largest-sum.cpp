class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<pair<int,int>> pq;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            pq.push({nums[i], i});
        }
        vector<int> ans(k);
        for(int i = 0; i<k; i++){
            ans[i] = pq.top().second;
            pq.pop();
        }
        sort(ans.begin(), ans.end());
        for(int i = 0; i<k; i++){
            ans[i] = nums[ans[i]];
        }
        return ans;
    }
};
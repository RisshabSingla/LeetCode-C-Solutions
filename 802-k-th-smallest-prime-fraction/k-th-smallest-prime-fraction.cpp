class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<pair<double, pair<int,int>>, vector<pair<double, pair<int,int>>>, greater<pair<double, pair<int,int>>>>  pq;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                double d = ((double)arr[i])/((double)arr[j]);
                pq.push({d, {i,j}});
            }
        }
        vector<int> ans;
        for(int i = 0; i<k-1; i++){
            pq.pop();
        }
        ans.push_back(arr[pq.top().second.first]);
        ans.push_back(arr[pq.top().second.second]);
        return ans;
    }
};
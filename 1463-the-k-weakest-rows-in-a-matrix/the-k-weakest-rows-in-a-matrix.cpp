class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        priority_queue<pair<int,int>, vector<pair<int,int>>,greater<pair<int,int>> > pq;
        vector<int> ans;
        for(int i = 0; i<mat.size();i++){
            int count = 0;
            while(count < mat[0].size() && mat[i][count] == 1){
                count++;
            }
            pq.push({count, i});
            // cout<<"i: "<<i<<" count: "<<count<<endl;
        }

        while(k--){
            ans.push_back(pq.top().second);
            // cout<<pq.top().first<<" "<<<<endl;
            pq.pop();
        }
        return ans;
    }
};
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& edges, int n, int k) {
        vector<int> time(n, 10000);
        time[k-1] = 0;
        int nEdges = edges.size();
        for(int j = 0; j<n; j++){
            bool changed = false;
            for(int i = 0; i<nEdges; i++){
                if(time[edges[i][0]-1] != 10000 && time[edges[i][1]-1] > time[edges[i][0]-1] + edges[i][2]){
                    time[edges[i][1]-1] = time[edges[i][0]-1] + edges[i][2];
                    changed = true;
                }
            }
            if(!changed){
                break;
            }
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, time[i]);
            if(time[i] == 10000){
                return -1;
            }
        }
        return ans;
    }
};
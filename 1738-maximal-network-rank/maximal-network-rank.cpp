class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<int> indegree(n,0);
        vector<vector<int>> adj(n, vector<int>(n,0));
        for(int i = 0; i<roads.size(); i++){
            indegree[roads[i][0]]++;
            indegree[roads[i][1]]++;
            adj[roads[i][0]][roads[i][1]] = 1;
            adj[roads[i][1]][roads[i][0]] = 1;
        }



        int max_rank = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int c = indegree[i] + indegree[j] - adj[i][j];
                max_rank = max(max_rank, c);
            }
        }
        return max_rank;
    }
};
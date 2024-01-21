class Solution {
public:
    vector<int> countOfPairs(int n, int x, int y) {
        vector<vector<long long>> adj(n, vector<long long> (n,INT_MAX));
        for(int i = 0; i<n-1; i++){
            adj[i][i] = 0LL;
            adj[i][i+1] = 1LL;
            adj[i+1][i] = 1LL;
        }
        adj[x-1][y-1] = min(adj[x-1][y-1], 1LL);
        adj[y-1][x-1] = min(adj[y-1][x-1], 1LL);
        adj[n-1][n-1] = 0;
//         for(auto i: adj){
//             for(auto j: i){
//                 cout<<j<<" ";
//             }
//             cout<<"\n";
//         }
        for (int k = 0; k < n; k++) {
        // Pick all vertices as source one by one
        for (int i = 0; i < n; i++) {
            // Pick all vertices as destination for the
            // above picked source
            for (int j = 0; j < n; j++) {
                // If vertex k is on the shortest path from
                // i to j, then update the value of
                // dist[i][j]
                if (adj[i][j] > (adj[i][k] + adj[k][j])
                    && (adj[k][j] != INT_MAX
                        && adj[i][k] != INT_MAX))
                    adj[i][j] = adj[i][k] + adj[k][j];
            }
        }
        
    }
        // for(auto i: adj){
        //     for(auto j: i){
        //         cout<<j<<" ";
        //     }
        //     cout<<"\n";
        // }
        vector<int> ans(n+1,0);
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(adj[i][j] != INT_MAX ){
                    ans[adj[i][j]]++;
                }
            }
        }
        ans.erase(ans.begin());
        return ans;
    }
    
};
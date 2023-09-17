class Solution {
public:
    int getLength(vector<vector<int>>& graph, int &start, int &nodes){
        int final_bit = pow(2,nodes)-1;
        queue<pair<int,int>> q;
        q.push({start, 1<<start});
        // vector<int> last_occ(nodes, 0);
        map<pair<int,int>,int> dp;
        dp[{start, 1<<start}] = 0;
        // unordered_set<pair<int,pair<int,int>>> dp;
        // dp.insert({start, {1<<start,0}});
        // last_occ[start] = 1<<start;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            for(int i = 0; i<graph[p.first].size(); i++){
                int v = graph[p.first][i];
                int new_mask = p.second | 1<<v;
                if(new_mask == final_bit){
                    return dp[{p.first,p.second}] + 1;
                }
                if(dp.count({v,new_mask}) == 0){
                    dp[{v,new_mask}] = dp[{p.first,p.second}] + 1;
                    q.push({v, new_mask});
                }
            }
        }
        return INT_MAX;
    }
    int shortestPathLength(vector<vector<int>>& graph) {
        int nodes = graph.size();
        int shortest_length = INT_MAX;
        
        for(int start = 0; start<nodes; start++){
            shortest_length = min(shortest_length, getLength(graph, start, nodes));
        }
        if(shortest_length == INT_MAX){
            return 0;
        }
        return shortest_length;
    }
};
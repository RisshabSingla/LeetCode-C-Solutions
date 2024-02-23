class Compare {
public:
    bool operator()(vector<int>&a, vector<int>& b) { 
        if(a[0] == b[0]){
            return a[2] < b[2];
        }
        return a[0] < b[0];
    }
};
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n, INT_MAX);
        vector<vector<vector<int>>> adj_list(n);
        for(auto &i : flights){
            adj_list[i[0]].push_back({i[1], i[2]});
            // adj_mat[i[0]][i[1]] = i[2];
        }
        costs[src] = 0;
        priority_queue<vector<int>, vector<vector<int>>, Compare>pq;
        // stop, node, cost
        pq.push({0, src, 0});
        while(!pq.empty()){
            vector<int> top = pq.top();
            // for(auto j: top){
            //     cout<<j<<' ';
            // }
            // cout<<"\n";
            pq.pop();
            // k++;
            // for(int i = 0; i<adj_list[top[1]].size(); i++){
            //     int node = adj_list[top[1]][i][0];
            //     int c =  adj_list[top[1]][i][1];
            //     int new_c = c + top[2];
            //     // if(node == dest)
            //     // cout<<"Pushed: "<<top[0]+1<<" node: "<<node<<" cost: "<<new_c<<"\n";
            //     if(node == dst && top[0]<=k +1){
            //         costs[node] = min(new_c,costs[node]);
            //     }
            //     if(costs[node] > new_c && top[0] + 1 <= k){
            //         pq.push({top[0]+1, node, new_c});
            //         costs[node] = min(new_c,costs[node]);
            //     }
            // }

            for(auto &i: adj_list[top[1]]){
                int new_c = i[1] + top[2];
                if(i[0] == dst && top[0]<=k +1){
                    costs[i[0]] = min(new_c,costs[i[0]]);
                }
                if(costs[i[0]] > new_c && top[0] + 1 <=k){
                    pq.push({top[0] +1, i[0], new_c});
                    costs[i[0]] = min(new_c,costs[i[0]]);
                }
            }
        }
        if(costs[dst] == INT_MAX){
            return -1;
        }
        return costs[dst];
    }
};
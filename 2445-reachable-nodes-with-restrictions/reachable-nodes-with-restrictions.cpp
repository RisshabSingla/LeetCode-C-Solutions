class Solution {
public:
    int findParent(int node, vector<int> &parent){
        if(node == -1){
            return -1;
        }
        if(node == parent[node]){
            return node;
        }
        int a = findParent(parent[node], parent);
        if(a == -1){
            return -1;
        }
        return parent[node] = a;
    }
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int nEdges = edges.size();
        vector<int> parent(n, 0);
        vector<bool> visited(n, false);
        for(int i = 0; i<restricted.size(); i++){
            parent[restricted[i]] = -1;
        }

        unordered_map<int, vector<int>> adj;
        for(auto&i: edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        queue<int> q;
        q.push(0);
        int count = 0;
        visited[0] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            count++;
            for(auto &i: adj[node]){
                if(!visited[i] && parent[i] != -1){
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        return count;


        // for(int i = 0; i<nEdges; i++){
        //     int a = findParent(edges[i][0], parent);
        //     int b = findParent(edges[i][1], parent);
        //     if(a!= -1 && b!=-1){
        //         parent[a] = b;
        //     }
        // }
        // for(auto &i: parent){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // int count = 0;
        // for(int i = 0;i<n; i++){
        //     if(parent[i] == -1 || (parent[i] == i && i != parent[0])){
        //         continue;
        //     }
        //     count++;
        // }
        // return count;
    }
};
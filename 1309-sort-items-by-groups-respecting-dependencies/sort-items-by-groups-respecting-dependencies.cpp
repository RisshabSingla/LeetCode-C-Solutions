class Solution {
public:
    vector<int>toposort(int n, vector<vector<int>>& adj, vector<int>& indegree){
        queue<int>q;
        vector<int>order;
        vector<int>vis(n, 0);

        for(int i=0; i<n; i++){
            if(vis[i]==0 && indegree[i]==0){
                q.push(i);
                order.push_back(i);
                vis[i]=1;
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();

            for(auto i: adj[node]){
                if(vis[i]==0){
                    indegree[i]--;
                    if(indegree[i]==0){
                        q.push(i);
                        order.push_back(i);
                        vis[i]=1;
                    }
                }
                
            }            
        }
        return order;
    }
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& before) {
        int groupid = m;
        for (int i = 0; i < n; i++) {
            if (group[i] == -1) {
                group[i] = groupid;
                groupid++;
            }
        }

        //item graph
        vector<vector<int>>item_graph(n);
        vector<int>item_indegree(n);

        for(int i=0; i<n; i++){
            for(auto it: before[i]){
                item_graph[it].push_back(i);
                item_indegree[i]++;
            }
        }

        //group graph
        vector<vector<int>>grp_graph(groupid);
        vector<int>grp_indegree(groupid);

        for(int i=0; i<n; i++){
            for(auto it: before[i]){
                if(group[it]!=group[i]){
                    grp_graph[group[it]].push_back(group[i]);
                    cout<<group[i]<<endl;
                    grp_indegree[group[i]]++;
                }
            }
        }

        //item toposort
        vector<int> item_order= toposort(n, item_graph, item_indegree);

        //group toposort
        vector<int> grp_order= toposort(groupid, grp_graph, grp_indegree);


        if(item_order.size() < n || grp_order.size() < groupid){
            return {};
        }

        map<int, vector<int>>map;

        for(int i=0; i<n; i++){
            int node= item_order[i];
            map[group[node]].push_back(node);
        }

        vector<int>ans;
        for(auto i: grp_order){
            for(auto it: map[i]){
                ans.push_back(it);
            }
        }
        
        return ans;

    }
};
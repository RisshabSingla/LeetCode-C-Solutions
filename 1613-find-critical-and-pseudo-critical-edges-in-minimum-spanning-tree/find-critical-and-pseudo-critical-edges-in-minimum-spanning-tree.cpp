class Solution {
public:
    static bool comp(vector<int> a, vector<int> b){
        return a[2] < b[2];
    }
    int kruskal(int n, vector<vector<int>>& edges, int skip_edge = -1, int include_edge = -1){
        // cout<<"Skip_edge is: "<<skip_edge<<" inc: "<<include_edge<<endl;
        vector<int> parent(n);
        for(int i = 0; i<n; i++){
            parent[i] = i;
        }

        int count = 0;
        int index = 0;
        int total_weight = 0;
        // bool skipped = false;

        if(include_edge != -1){
            vector<int> e = edges[include_edge];
            total_weight+= e[2];
            count++;
            parent[e[1]] = e[0];
        }


        while(count != n-1 && index < edges.size()){
            if(index == skip_edge){
                // skipped = true;
                index++;
            }
            if(index == edges.size()){
                break;
            }
            int source = edges[index][0];
            int dest = edges[index][1];
            int weight = edges[index][2];

            int p1 = parent[source];
            while(p1!= parent[p1]){
                p1 = parent[p1];
            }

            int p2 = parent[dest];
            while(p2!= parent[p2]){
                p2 = parent[p2];
            }

            if(p1 != p2){
                total_weight+= weight;
                // parent[v1] = min(p1, p2);
                // parent[v2] = min(p1, p2);
                parent[p2] = p1;
                count++;
            }
            index++;
        }
        if(count!= n-1){
            return INT_MAX;
        }
        // if(skip_edge != -1){
        //     if(skipped){
        //         return total_weight;
        //     }
        //     return INT_MAX;
        // }
        return total_weight;
        // return 0;
    }   
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {

        // vector<vector<int>> ans;
        // return ans;

        for(int i = 0; i<edges.size(); i++){
            edges[i].push_back(i);
            // storing the edge number in the vector itself
        }
        sort(edges.begin(), edges.end(), comp);
        for(auto i: edges){
            for(auto j: i){
                cout<<j<<" ";
            }
            cout<<endl;
        }
        int min_cost = kruskal(n, edges);
        // cout<<"Min Cost is: "<<min_cost<<endl;
        vector<int> critical;
        vector<int> pseudo;
        for(int i = 0; i<edges.size(); i++){
            // cout<<"Calling for edge: "<<i<<endl;
            int skip_cost = kruskal(n, edges, i);
            int inc_cost = kruskal(n,edges, -1, i);
            // cout<<"Skip Cost is: "<<skip_cost
            //     <<" Inc Cost is: "<<inc_cost 
            //     <<" edge: "<<edges[i][3]<<endl;
            if(skip_cost > min_cost){
                // cout<<"Pushed: "<<edges[i][3]<<" in critical"<<endl;
                critical.push_back(edges[i][3]);
            }else if(inc_cost == min_cost){
                // cout<<"Pushed: "<<edges[i][3]<<" in pseudo"<<endl;
                pseudo.push_back(edges[i][3]);
            }
            // if(cost == INT_MAX){
            //     continue;
            // }
            // if(cost == min_cost){
                
            // }else{
                
            // }
            cout<<endl;
        }
        // cout<<"Out of the loop"<<endl;
        vector<vector<int>> ans;
        ans.push_back(critical);
        ans.push_back(pseudo);
        return ans;
    }
};
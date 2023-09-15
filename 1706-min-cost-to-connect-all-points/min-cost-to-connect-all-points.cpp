class Solution {
public:

    int calcDistance(int index, vector<int> &dsu, 
        vector<vector<int>>& points){
        
        int dis = INT_MAX;
        for(int i = 0; i<dsu.size(); i++){
            int d = abs(points[index][0]-points[dsu[i]][0]) + abs(points[index][1]-points[dsu[i]][1]);
            dis = min(dis, d);
        }
        return dis;
    }


    int calcDistance(int index, unordered_set<int> &dsu, 
        vector<vector<int>>& points){
        
        int dis = INT_MAX;
        for(auto i : dsu){
            int d = abs(points[index][0]-points[i][0]) + abs(points[index][1]-points[i][1]);
            dis = min(dis, d);
        }
        return dis;
    }


    int constructMST(vector<pair<int, pair<int,int>>> &edges, int n){
        int cost = 0;
        vector<int> parent(n);
        for(int i = 0; i<n;i++){
            parent[i] = i;
        }

        int count = 0;
        int index = 0;
        while(count != n-1){
            int v1 = edges[index].second.first;
            int v2 = edges[index].second.second;
            int weight = edges[index].first;

            int p1 = parent[v1];
            while(p1!= parent[p1]){
                p1 = parent[p1];
            }

            int p2 = parent[v2];
            while(p2!= parent[p2]){
                p2 = parent[p2];
            }

            if(p1 != p2){
                cost+= weight;
                parent[p2] = p1;
                count++;
            }
            index++;
        }

        return cost;



    }




    int minCostConnectPoints(vector<vector<int>>& points) {
        
        // Using vector for DSU

        // int size = points.size();
        // int total_cost = 0;
        // vector<int> dsu;
        // dsu.push_back(0);

        // while(dsu.size() != size){
        //     int cost = INT_MAX;
        //     int index = 0;
        //     for(int i = 0; i<size; i++){
        //         if(find(dsu.begin(), dsu.end(), i) == dsu.end()){
        //             // that point is not included in the dsu
        //             int dis = calcDistance(i, dsu, points);
        //             if(cost>dis){
        //                 cost = dis;
        //                 index = i;
        //             }
        //         }
        //     }
        //     total_cost += cost;
        //     dsu.push_back(index);
        // }
        // return total_cost;



        // Using Set for DSU

        // int size = points.size();
        // int total_cost = 0;
        // unordered_set<int> dsu;
        // dsu.insert(0);

        // while(dsu.size() != size){
        //     int cost = INT_MAX;
        //     int index = 0;
        //     for(int i = 0; i<size; i++){
        //         if(dsu.count(i) == 0){
        //             // that point is not included in the dsu
        //             int dis = calcDistance(i, dsu, points);
        //             if(cost>dis){
        //                 cost = dis;
        //                 index = i;
        //             }
        //         }
        //     }
        //     total_cost += cost;
        //     dsu.insert(index);
        // }
        // return total_cost;

        int n = points.size();
        // vector<vector<int>> adj_mat(n, vector<int> (n,-1));

        // for(int i = 0; i<n; i++){
        //     for(int j = 0; j<n; j++){
        //         adj_mat[i][j] = calcDistance(points[i], points[j]);
        //     }
        // }

        vector<pair<int, pair<int,int>>> edges;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                int d = abs(points[i][0]-points[j][0])+ 
                        abs(points[i][1]-points[j][1]);
                edges.push_back({d, {i,j}});
            }
        }

        sort(edges.begin(), edges.end());

        int cost = constructMST(edges,n);
        return cost;

    }
};
class Solution {
public:
    vector<int> findDistance(int source, int nodes, vector<vector<pair<int,int>>> &graph){
        vector<int> distances(nodes, INT_MAX);
        vector<int> visited(nodes, false);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0, source});

        while(!pq.empty()){
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();
            if(visited[node]){
                continue;
            }
            visited[node] = true;
            distances[node] = dis;

            for(auto &i: graph[node]){
                if(!visited[i.first]){
                    pq.push({dis+i.second, i.first});
                }
            }
        }
        return distances;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto &i: edges){
            graph[i[0]].push_back({i[1], i[2]});
            graph[i[1]].push_back({i[0], i[2]});
        }

        vector<int> sourceDistance = findDistance(0, n, graph);
        vector<int> destDistance = findDistance(n-1, n, graph);

        long long shortestDistance = sourceDistance[n-1];
        vector<bool> ans(edges.size(), false);
        int index = 0;
        for(auto &i: edges){
            // int source = i[0];
            // int dest = i[1];
            // long long cost = i[2];
            // if(sourceDistance[source] + cost + destDistance[dest] == shortestDistance){
            //     ans[index] = true;
            // }

            // if(sourceDistance[dest] + cost + destDistance[source] == shortestDistance){
            //     ans[index] = true;
            // }
            if(sourceDistance[i[0]] + (long long)(i[2]) + destDistance[i[1]] == shortestDistance){
                ans[index] = true;
            }

            if(sourceDistance[i[1]] + (long long)(i[2]) + destDistance[i[0]] == shortestDistance){
                ans[index] = true;
            }
            index++;
        }
        return ans;
    }
};
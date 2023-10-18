class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        map<int, vector<int>> graph;
        vector<int> indegree(n, 0);
        for(int i = 0; i<relations.size(); i++){
            graph[relations[i][0]-1].push_back(relations[i][1]-1);
            indegree[relations[i][1]-1]++;
        }
        queue<int> q;
        vector<int> max_time(n, 0);
        for(int i = 0; i<n; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
            max_time[i] = time[i];
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(int i = 0; i<graph[node].size(); i++){
                int neighbor = graph[node][i];
                indegree[neighbor]--;
                max_time[neighbor] = max(max_time[neighbor], max_time[node] + time[neighbor]);
                if(indegree[neighbor] == 0){
                    q.push(neighbor);
                }
            }        
        }
        int ans = 0;
        for(int i = 0; i<n; i++){
            ans = max(ans, max_time[i]);
        }
        return ans;
    }
};
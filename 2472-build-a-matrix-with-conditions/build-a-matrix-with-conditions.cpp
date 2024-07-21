class Solution {
public:
    vector<vector<int>> makeGraph(vector<vector<int>>& conditions, int k) {
        vector<vector<int>> graph(k + 1);
        for (auto& i : conditions) {
            graph[i[0]].push_back(i[1]);
        }
        return graph;
    }

    vector<int> doTopoSort(vector<vector<int>>& graph, int k) {
        vector<int> indegree(k + 1, 0);
        for (auto& src : graph) {
            for (auto dest : src) {
                indegree[dest]++;
            }
        }

        queue<int> q;
        for (int i = 1; i <= k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int src = q.front();
            q.pop();
            ans.push_back(src);
            for (int dest : graph[src]) {
                indegree[dest]--;
                if (indegree[dest] == 0) {
                    q.push(dest);
                }
            }
        }
 
        for (int i = 1; i <= k; i++) {
            if (indegree[i] != 0) {
                return {};
            }
        }

        return ans;
    }

    void fillTopoArray(vector<int>&topoSort, int k){
        unordered_map<int,int> mp;
        for(auto i: topoSort){
            mp[i]++;
        }
        for(int i = 1;i<=k; i++){
            if(!mp.count(i)){
                topoSort.push_back(i);
            }
        }
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions,
                                    vector<vector<int>>& colConditions) {
        vector<vector<int>> rowGraph = makeGraph(rowConditions, k);
        vector<vector<int>> colGraph = makeGraph(colConditions, k);

        vector<int> rowTopo = doTopoSort(rowGraph, k);
        vector<int> colTopo = doTopoSort(colGraph, k);
        if(rowTopo.size() == 0 || colTopo.size() == 0){
            return {};
        }

        fillTopoArray(rowTopo,k);
        fillTopoArray(colTopo,k);

        unordered_map<int,int> colIndexes;
        for(int i = 0; i<k; i++){
            colIndexes[colTopo[i]] = i;
        }

        vector<vector<int>> ans(k, vector<int> (k,0));
        for(int i = 0; i<k;i++){
            ans[i][colIndexes[rowTopo[i]]] = rowTopo[i];
        }
        return ans;
    }
};
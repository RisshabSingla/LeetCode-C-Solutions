class Solution {
public:
    // int findHeight(int root, unordered_map<int, vector<int>>& adj, int n) {
    //     vector<bool> visited(n, false);
    //     queue<int> q;
    //     q.push(root);
    //     q.push(-1);
    //     visited[root] = true;
    //     int height = 0;
    //     while (!q.empty()) {
    //         int node = q.front();
    //         q.pop();
    //         if (node == -1) {
    //             if (!q.empty()) {
    //                 q.push(-1);
    //             }
    //             height++;
    //             continue;
    //         }
    //         for (auto& i : adj[node]) {
    //             if (!visited[i]) {
    //                 q.push(i);
    //                 visited[i] = true;
    //             }
    //         }
    //     }
    //     return height;
    // }

    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) {
            return {0};
        }
        // Approach 1: Finding height for every node

        // unordered_map<int, vector<int>> adj;
        // vector<int> degree(n, 0);
        // int maxi = 0;
        // for (auto& i : edges) {
        //     adj[i[0]].push_back(i[1]);
        //     adj[i[1]].push_back(i[0]);
        //     degree[i[0]]++;
        //     degree[i[1]]++;
        //     maxi = max({maxi, degree[i[0]], degree[i[1]]});
        // }
        // vector<int> ans;
        // int height = INT_MAX;
        // for (int root = 0; root < n; root++) {
        //     if(maxi > 1 && degree[root] < 2){
        //         continue;
        //     }
        //     int h = findHeight(root, adj, n);
        //     if (h <= height) {
        //         if (h < height) {
        //             ans.clear();
        //         }
        //         height = h;
        //         ans.push_back(root);
        //     }
        // }
        // return ans;

        // Approach 2

        unordered_map<int, vector<int>> adj;
        vector<int> degree(n, 0);
        int maxi = 0;
        for (auto& i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            degree[i[0]]++;
            degree[i[1]]++;
        }

        queue<int> q;
        int nodes = n;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) {
                degree[i]--;
                q.push(i);
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            int size = q.size();
            ans.clear();
            for (int i = 0; i < size; i++) {
                int node = q.front();
                q.pop();
                ans.push_back(node);
                for (auto& i : adj[node]) {
                    degree[i]--;
                    if (degree[i] == 1) {
                        q.push(i);
                    }
                }
            }
        }

        return ans;
    }
};
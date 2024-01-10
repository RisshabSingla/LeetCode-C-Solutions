class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<long long>> distance(n, vector<long long>(n, INT_MAX));
        for (int i = 0; i < edges.size(); i++) {
            vector<int> edge = edges[i];
            distance[edge[0]][edge[1]] = edge[2];
            distance[edge[1]][edge[0]] = edge[2];
        }
        for (int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }
        for (int via = 0; via < n; via++) {
            for (int to = 0; to < n; to++) {
                for (int from = 0; from < n; from++) {
distance[from][to] = min(distance[from][to], distance[from][via] + distance[via][to]);
                }
            }
        }
        int node = 0;
        int count = n;
        for (int i = 0; i < n; i++) {
            int c = 0;
            for (int j = 0; j < n; j++) {
                if (distance[i][j] <= distanceThreshold) {
                    c++;
                }
            }
            if (c <= count) {
                node = i;
                count = c;
            }
        }
        return node;
    }
    
};
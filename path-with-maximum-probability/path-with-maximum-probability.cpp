class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];
            graph[u].push_back({v, p});
            graph[v].push_back({u, p});
        }
        
        vector<double> maxp(n, 0.00);
        maxp[start] = 1.00;

        priority_queue<pair<double, int>> pq;
        pq.push({1.00, start});

        while (!pq.empty()) {
            double prob = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (node == end) {
                return prob;
            }

            for (auto neighbor : graph[node]) {
                int adj = neighbor.first;
                double edgeProb = neighbor.second;
                double newProb = prob * edgeProb;
                if (newProb > maxp[adj]) {
                    maxp[adj] = newProb;
                    pq.push({newProb, adj});
                }
            }
        }
        
        return maxp[end];
    }
};
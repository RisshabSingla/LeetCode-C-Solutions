class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        vector<vector<pair<int, double>>> graph(n);
        for (int i = 0; i < edges.size(); i++) {
            graph[edges[i][0]].push_back({edges[i][1], succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0], succProb[i]});
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
                if (prob * neighbor.second > maxp[neighbor.first]) {
                    maxp[neighbor.first] = prob * neighbor.second;
                    pq.push({prob * neighbor.second, neighbor.first});
                }
            }
        }
        
        return maxp[end];
    }
};
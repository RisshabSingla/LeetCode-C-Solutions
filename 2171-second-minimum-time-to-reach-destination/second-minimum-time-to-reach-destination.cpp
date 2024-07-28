class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<pair<long long, long long>> times(n, {INT_MAX, INT_MAX});
        times[0] = {0, INT_MAX};
        vector<vector<int>> adjList(n);
        for (auto &i : edges) {
            adjList[i[0] - 1].push_back(i[1] - 1);
            adjList[i[1] - 1].push_back(i[0] - 1);
        }
        queue<int> q;
        q.push(0);
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            long long first = times[node].first;
            long long second = times[node].second;
            if (first != INT_MAX) {
                int div = first / change;
                if (div % 2) {
                    first = (div + 1) * change;
                }
            }
            if (second != INT_MAX) {
                int div = second / change;
                if (div % 2) {
                    second = (div + 1) * change;
                }
            }
            for (auto neighbor : adjList[node]) {
                if (times[neighbor].first > first + time) {
                    times[neighbor].second = times[neighbor].first;
                    times[neighbor].first = first + time;
                    q.push(neighbor);
                } else if (first + time > times[neighbor].first &&
                           times[neighbor].second > first + time) {
                    times[neighbor].second = first + time;
                    q.push(neighbor);
                } else if (second + time > times[neighbor].first &&
                           times[neighbor].second > second + time) {
                    times[neighbor].second = second + time;
                    q.push(neighbor);
                }
            }
        }
        return (int)times[n - 1].second;
    }
};
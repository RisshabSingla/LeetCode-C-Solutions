class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits,
                             vector<int>& capital) {
        int n = profits.size();
        int curr = w;
        vector<pair<int, int>> projects(n);
        for (int i = 0; i < n; i++) {
            projects[i] = {capital[i], profits[i]};
        }
        sort(projects.begin(), projects.end());
        int index = 0;
        priority_queue<int> maximizeCapital;
        while (k--) {
            while (index < n && projects[index].first <= curr) {
                maximizeCapital.push(projects[index].second);
                index++;
            }
            if (maximizeCapital.empty())
                break;
            curr += maximizeCapital.top();
            maximizeCapital.pop();
        }
        return curr;
    }
};
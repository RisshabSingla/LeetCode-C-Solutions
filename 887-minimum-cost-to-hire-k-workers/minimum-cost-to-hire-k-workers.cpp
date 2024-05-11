class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage,
                                int k) {
        vector<pair<double, int>> ratio;
        int n = quality.size();

        for (int i = 0; i < n; i++) {
            ratio.push_back({(double)(wage[i]) / quality[i], i});
        }

        sort(ratio.begin(), ratio.end());
        priority_queue<int> hp;
        int qualitySum = 0;
        double maxRate = 0.0;

        for (int i = 0; i < k; i++) {
            qualitySum += quality[ratio[i].second];
            maxRate = max(maxRate, ratio[i].first);
            hp.push(quality[ratio[i].second]);
        }

        double res = maxRate * qualitySum;
        for (int i = k; i < n;i++) {
            maxRate = max(maxRate, ratio[i].first);
            qualitySum -= hp.top();
            hp.pop();

            qualitySum += quality[ratio[i].second];
            hp.push(quality[ratio[i].second]);
            res = min(res, maxRate * qualitySum);
        }

        return res;
    }
};
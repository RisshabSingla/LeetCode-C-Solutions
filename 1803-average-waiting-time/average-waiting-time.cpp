class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        double wait = 0;
        double chefTime = 0;
        for (auto &customer: customers) {
            chefTime = max(chefTime, 1.0 * customer[0]) + customer[1];
            wait += chefTime - customer[0];
        }
        return 1.0 * wait / customers.size();
    }
};
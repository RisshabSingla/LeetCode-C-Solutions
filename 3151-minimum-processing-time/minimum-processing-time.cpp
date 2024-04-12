class Solution {
public:
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        int maxi = 0;
        for(int i = 0; i<processorTime.size(); i++){
            int index = 4*i;
            for(int j = 0; j<4; j++){
                maxi = max(maxi, processorTime[i] + tasks[index+j]);
            }
        }
        return maxi;
    }
};
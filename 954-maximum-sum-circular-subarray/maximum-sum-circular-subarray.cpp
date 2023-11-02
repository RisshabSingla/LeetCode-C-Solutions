class Solution {
public:
    int maxSubarraySumCircular(vector<int>& arr) {
        int n = arr.size();
        int max_sum = INT_MIN;
        int max_curr_sum = 0;
        int array_sum = 0;
        int min_sum = 0;
        int min_curr_sum = 0;
        for (int i = 0; i < n; i++)
        {
            array_sum += arr[i];
            max_curr_sum += arr[i];
            max_sum = max(max_sum, max_curr_sum);
            if (max_curr_sum < 0)
            {
                max_curr_sum = 0;
            }
            min_curr_sum += arr[i];
            min_sum = min(min_sum, min_curr_sum);
            if (min_curr_sum > 0)
            {
                min_curr_sum = 0;
            }
        }
        if (array_sum == min_sum)
        {
            return  max_sum;
        }
        else
        {
            return  max(max_sum, array_sum - min_sum);
        }
        return 0;
    }
};
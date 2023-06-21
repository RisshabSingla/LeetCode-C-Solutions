class Solution
{
public:
    long long minCost(vector<int> &nums, vector<int> &cost)
    {
        int size = nums.size();
        vector<pair<long long, long long> > arr(size);
        long long freq = 0;
        // making a pair vector for sorting
        // also calculating the total freq for median
        for (int i = 0; i < size; i++)
        {
            arr[i].first = nums[i];
            arr[i].second = cost[i];
            freq += cost[i];
        }

        sort(arr.begin(), arr.end());
        long long index = freq / 2;
        freq = 0;
        long long number = 0; // median number

        // finding the median element
        for (int i = 0; i < size; i++)
        {
            freq += arr[i].second;
            if (freq > index)
            {
                number = arr[i].first;
                break;
            }
        }
        // cout << "Median is: " << number << endl;        
        long long min_cost = 0;
        for (int i = 0; i < size; i++)
        {
            long long a = (long long)abs((arr[i].first - number));
            min_cost += a * (long long)arr[i].second;
        }
        return min_cost;
    }
};
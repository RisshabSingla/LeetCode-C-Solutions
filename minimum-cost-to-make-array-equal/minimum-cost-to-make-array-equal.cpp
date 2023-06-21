class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int size = nums.size();
        vector<pair<long long,long long>> arr(size);
        long long freq = 0;
        // making a pair vector for sorting
        // also calculating the total freq for median
        for(int i = 0; i<size; i++){
            arr[i].first = nums[i];
            arr[i].second = cost[i];
            freq+=cost[i];
        }

        sort(arr.begin(), arr.end());
        long long index = freq/2;
        index--;
        freq = 0;
        long long number = 0;

        // finding the median element 
        int next_number = 0;
        for(int i = 0; i<size; i++){
            freq+=arr[i].second;
            if(freq>index){
                number = arr[i].first;
                if(i<size-1){
                    next_number = arr[i+1].first;
                }
                break;
            }
        }
        cout<<"Median is: "<<number<<endl;
        int count = 0;
        // number--;
        long long min_cost = LLONG_MAX;
        // for(int i = 0; i<size; i++){
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }

        // while(count<3){
            long long c = 0;
            cout<<"Making the number to: "<<number<<endl;
            for(int i = 0; i<size; i++){
                long long a = (long long)abs((arr[i].first-number));
                c+= a*(long long)arr[i].second;
            }
            cout<<"cost is: "<<c<<endl;
            min_cost = min(min_cost, c);
            count++;
            // number++;
        // }

        // long long 
        c = 0;
        cout<<"Making the number to: "<<next_number<<endl;
        for(int i = 0; i<size; i++){
            long long a = (long long)abs((arr[i].first-next_number));
            c+= a*(long long)arr[i].second;
        }
        cout<<"cost is: "<<c<<endl;
        min_cost = min(min_cost, c);

        return min_cost;
    }
};
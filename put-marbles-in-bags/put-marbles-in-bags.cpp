class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        // Approach 1: Using Priority Queue
        // int size = weights.size();
        // priority_queue<int> max_heap;
        // priority_queue<int, vector<int>, greater<int> > min_heap;
        // for(int i = 0;i<size-1; i++){
        //     max_heap.push(weights[i] + weights[i+1]);
        //     min_heap.push(weights[i] + weights[i+1]);
        // }
        // int partitions = k-1;
        // long long ans = 0;
        // while(partitions--){
        //     ans+=max_heap.top();
        //     ans-=min_heap.top();
        //     max_heap.pop();
        //     min_heap.pop();
        // }
        // return ans;

        // Approach 2: Using vector and sort

        int size = weights.size();
        vector<int> sum;
        for(int i = 0; i<size-1; i++){
            sum.push_back(weights[i]+ weights[i+1]);
        }
        sort(sum.begin(), sum.end());
        long long ans = 0;
        int index = 0;
        while(index < k-1){
            ans-= sum[index];
            ans+= sum[size-2-index];
            index++;
        }
        return ans;
    }
};
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long,vector<long long>, greater<long long>> pq;
        for(int i = 0; i<nums.size(); i++){
                pq.push(nums[i]);
        }
        int count = 0;
        while(!pq.empty()){
            long long x = pq.top();
            if(x >= k){
                break;
            }
            pq.pop();
            long long y = pq.top();
            pq.pop();
            pq.push(min(x, y) * 2 + max(x, y));
            count++;
        }
        return count;
    }
};
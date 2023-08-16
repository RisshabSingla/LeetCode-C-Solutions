class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        
        // pq.push({nums[0],0});
        for(int i = 0; i<k; i++){
            pq.push({nums[i],i});
        }
        int size = nums.size();
        ans.push_back(pq.top().first);
        int front = 1;
        int end = k;
        for(int i = k; i<size; i++){
            pq.push({nums[i],i});
            while(pq.top().second<front){
                pq.pop();
            }
            front++;
            ans.push_back(pq.top().first);
        }
        return ans;
    }
};
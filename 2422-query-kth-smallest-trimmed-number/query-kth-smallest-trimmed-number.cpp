class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        int length = nums[0].length();
        int size = nums.size();
        for(auto &i: queries){
            priority_queue<pair<string,int>> pq;
            for(int j = 0; j<size; j++){
                string str = nums[j].substr(length-i[1]);
                pq.push({str, j});
            }
            int index = 0;
            while(index < size-i[0] && !pq.empty()){
                pq.pop();
                // cout<<"Popped"<<"\n";
                index++;
            }  
            ans.push_back(pq.top().second); 
            // cout<<"Pushing "<<pq.top().second<<"\n";
        }
        return ans;
    }
};
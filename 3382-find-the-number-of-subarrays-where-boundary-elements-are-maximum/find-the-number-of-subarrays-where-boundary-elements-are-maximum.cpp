class Solution {
public:
    long long numberOfSubarrays(vector<int>& nums) {
        // long long count = 0;
        // int n = nums.size();
        // Approach 1: Brute Force
        // for(int i = 0; i<n; i++){
        //     int maxi = nums[i];
        //     for(int j = i; j<n; j++){
        //         maxi = max(maxi, nums[j]);
        //         if(nums[i] == maxi && nums[j] == maxi){
        //             count++;
        //         }
        //     }
        // }
        // return count;


        // Approach 2: Using Stack
        int n = nums.size();
        long long count = 0;
        unordered_map<int, vector<int>> mp;
        // for(int i = 0; i<n; i++){
        //     mp[nums[i]].push_back(i);
        // }
        stack<int> stk;
        vector<int> nextBiggerIndex(n, -1);
        for(int i = 0; i<n; i++){
            if(stk.empty()){
                nextBiggerIndex[i] = -1;
            }else{
                while(!stk.empty() && nums[i] >= nums[stk.top()]){
                    stk.pop();
                }
                if(stk.empty()){
                    nextBiggerIndex[i] = -1;
                }else{
                    nextBiggerIndex[i] = stk.top();
                }
            }
            stk.push(i);
        }

        for(int i = 0; i<n; i++){
            int canStartFrom = nextBiggerIndex[i] + 1;
            if(mp[nums[i]].size() == 0){
                mp[nums[i]].push_back(i);
                count++;
                continue;
            }
            int size = mp[nums[i]].size();
            int index = lower_bound(mp[nums[i]].begin(),mp[nums[i]].end(), canStartFrom) - mp[nums[i]].begin();
            // cout<<"Index is: "<<index<<"\n";
            long long possible = size - index + 1;
            count+= possible;
            mp[nums[i]].push_back(i);
        }
        return count;
        // return count;
    }
};
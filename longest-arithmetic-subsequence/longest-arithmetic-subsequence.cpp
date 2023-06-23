class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        // Approach 1: Brute Force O(n^3)
        // int size = nums.size();
        // int max_count = 0;
        // for(int i = 0; i<size ; i++){
        //     for(int j = i+1; j<size; j++){
        //         int diff = nums[j] - nums[i];
        //         int next_num = nums[j] + diff;
        //         int count = 2;
        //         for(int k = j+1; k<size; k++){
        //             if(nums[k] == next_num){
        //                 next_num = next_num+ diff;
        //                 count++;
        //             }
        //         }
        //         max_count = max(count, max_count);
        //     }
        // }
        // return max_count;

        // Approach 2: Using Dynamic Programming


        int size = nums.size();
        unordered_map<int,int> dp[size+1];
        int ans = 0;
        for(int i = 1; i<size; i++){
            for(int j = 0; j<i; j++){
                int diff = nums[i] - nums[j];
                int count = 1;
                if(dp[j].count(diff)> 0){
                    count = dp[j][diff];
                }
                dp[i][diff] = count+1;
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans; 
    }
};
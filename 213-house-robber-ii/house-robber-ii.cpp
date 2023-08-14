class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return nums[0];
        }
        int prev_not_taken = 0;
        int prev_taken = 0;
        int curr_not_taken = 0;
        int curr_taken = 0;

        // not taking the first one 
        // can take the last house

        for(int i = 1; i<size; i++){
            curr_taken =  prev_not_taken + nums[i];
            curr_not_taken = max(prev_taken, prev_not_taken);

            prev_taken = curr_taken;
            prev_not_taken = curr_not_taken;
        }
        int ans1 = max(prev_taken, prev_not_taken);

        prev_not_taken = 0;
        prev_taken = 0;
        curr_not_taken = 0;
        curr_taken = 0;
        // considering the first house
        // last house not considered
        for(int i = 0; i<size-1; i++){
            curr_taken =  prev_not_taken + nums[i];
            curr_not_taken = max(prev_taken, prev_not_taken);

            prev_taken = curr_taken;
            prev_not_taken = curr_not_taken;
        }
        // int ans2 = max(prev_taken, prev_not_taken);

        return max({ans1, prev_taken,prev_not_taken});
    }
};
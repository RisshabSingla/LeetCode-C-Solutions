class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int moves = 0;
        int prev = nums[0];
        for(int i = 1; i<nums.size(); i++){
            if(nums[i] > prev+1){
                prev = nums[i];
                continue;
            }
            if(nums[i] == prev+1){
                prev = nums[i];
                continue;
            }
            moves+= (prev - nums[i] +1);
            prev++;
        }
        return moves;
    }
};
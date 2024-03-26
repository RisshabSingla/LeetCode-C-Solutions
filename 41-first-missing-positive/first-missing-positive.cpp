class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool containsOne = false;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] == 1){
                containsOne = true;
            }
            if(nums[i] <= 0 || nums[i] > n){
                nums[i] = 1;
            }
        }
        if(!containsOne){
            return 1;
        }

        for(int i = 0; i<n; i++){
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        }

        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
                return (i+1);
            }
        }
        return n+1;

    }
};
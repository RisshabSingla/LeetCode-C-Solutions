class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return true;
        }
        int index = 1;
        while(index <size && nums[index] == nums[index-1]){
            index++;
        }
        if(index == size){
            return true;
        }
        bool inc = nums[0]<nums[index];
        if(inc){
            // increasing
            for(int i = 1; i<size; i++){
                if(nums[i] < nums[i-1]){
                    return false;
                }
            }
            return true;
        }else{
            // decreasing
            for(int i = 1; i<size; i++){
                if(nums[i] > nums[i-1]){
                    return false;
                }
            }
            return true;
        }
        return true;
    }
};
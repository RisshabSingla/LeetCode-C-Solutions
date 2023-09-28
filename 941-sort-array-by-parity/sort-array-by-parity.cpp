class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int front = 0;
        int end = nums.size()-1;
        while(front<end){
            if(nums[front] % 2 == 0){
                // even number 
                front++;
            }else if(nums[end] % 2 == 1){
                // odd number 
                end--;
            }else{
                swap(nums[front], nums[end]);
            }
        }
        return nums;
    }
};
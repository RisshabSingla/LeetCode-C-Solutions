class Solution {
public:
    int sum = 0; 
    void findSum(vector<int> &nums, int index, int n, int curr){
        if(index == n){
            sum+= curr;
            return;
        }
        findSum(nums, index+1, n, curr xor nums[index]);
        findSum(nums, index+1, n, curr);
    }   
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();
        findSum(nums, 0, n, 0);
        return sum;
    }
};
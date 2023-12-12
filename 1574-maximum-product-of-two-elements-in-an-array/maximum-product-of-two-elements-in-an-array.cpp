class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // int max1 = INT_MIN;
        // int max2 = INT_MIN;

        // for (int i = 0; i<nums.size();i++) {
        //     if (nums[i] >= max1) {
        //         max2 = max1;
        //         max1 = nums[i];
        //     } else if (nums[i] > max2) {
        //         max2 = nums[i];
        //     }
        // }

        // return (max1 - 1) * (max2 - 1);
        sort(nums.begin(),nums.end());
        return (nums[nums.size()-1] - 1)  * (nums[nums.size()-2] - 1) ;
    }
};
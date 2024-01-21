class Solution {
public:
    int minimumArrayLength(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int min_elem = nums[0];
        int n = nums.size();
        int count = 0;
        for(int i = 0;i<n; i++){
            if(nums[i] % min_elem != 0){
                return 1;
            }
            if(nums[i] == min_elem){
                count++;
            }
        }
        return (count+1)/2;

    }
};
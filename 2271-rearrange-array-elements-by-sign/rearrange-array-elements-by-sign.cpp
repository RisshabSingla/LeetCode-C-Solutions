class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n/2);
        vector<int> neg(n/2);
        int index1 = 0;
        int index2 = 0;
        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
                pos[index1] = nums[i];
                index1++;
            }else{
                neg[index2] = nums[i];
                index2++;
            }
        }
        index1 = 0;
        index2 = 0;
        for(int i = 0; i<n; i++){
            if(i % 2 ==0){
                nums[i] = pos[index1];
                index1++;
            }else{
                nums[i] = neg[index2];
                index2++;
            }
        }
        return nums;
    }
};
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> pos;
        vector<int> neg;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            if(nums[i] > 0){
                pos.push_back(nums[i]);
            }else{
                neg.push_back(nums[i]);
            }
        }
        int index1 = 0;
        int index2 = 0;
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
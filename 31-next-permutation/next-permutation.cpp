class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int dip_index = -1;
        for(int i = size-2; i>=0; i--){
            if(nums[i]<nums[i+1]){
                dip_index = i;
                break;
            }
        }
        cout<<"Dip index: "<<dip_index<<endl;
        if(dip_index == -1){
            reverse(nums.begin(), nums.end());
            return;
        }

        for(int i = size-1; i>=dip_index; i--){
            if(nums[i]> nums[dip_index]){
                swap(nums[i], nums[dip_index]);
                break;
            }
        }

        reverse(nums.begin()+dip_index+1, nums.end());

    }
};
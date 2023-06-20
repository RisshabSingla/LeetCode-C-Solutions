class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int size = nums.size();
        vector<int> ans(size,-1);
        if(k == 0){
            return nums;
        }
        if(2*k>=size){
            return ans;
        }
        unsigned long long curr_sum = 0;
        for(int i = 0; i<=2*k; i++){
            curr_sum+=nums[i];
        }
        // cout<<"Curr sum is: "<<curr_sum<<endl;
        int start_index = 0;
        int end_index = 2*k+1;
        ans[k] = curr_sum/(2*k+1);
        for(int i = k+1; i<size && end_index<size; i++){
            // cout<<"Curr sum is: "<<curr_sum<<" for i: "<<i<<endl;
            curr_sum-=nums[start_index];
            // cout<<"Curr sum is: "<<curr_sum<<" after minus"<<endl;
            curr_sum+=nums[end_index];
            // cout<<"Curr sum is: "<<curr_sum<<" after add"<<endl;
            start_index++;
            end_index++;
            ans[i] = curr_sum/(2*k+1);
        }
        return ans;
    }
};
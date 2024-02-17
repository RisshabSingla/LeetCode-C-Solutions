class Solution {
public:
    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<int> sum(n, INT_MAX);
        int index = 0;
        for(int i = 0; i<n-1; i+=2){
            int s = nums[i] + nums[i+1];
            sum[index] = s;
            index++;
        }
        // for(int i = 0; i<n; i++){
        //     cout<<sum[i]<<" ";
        // }
        // cout<<"\n";
        index = 1;
        while(sum[index] == sum[index-1] && sum[index]!= INT_MAX){
            index++;
        }
        return index;
    }
};
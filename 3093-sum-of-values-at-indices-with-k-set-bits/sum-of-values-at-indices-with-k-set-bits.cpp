class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int ans = 0;
        int n = nums.size();
        for(int i = 0; i<n; i++){
            int count = 0;
            for(int j = 0;j<32; j++){
                if(i>>j & 1){
                    count++;
                }
            }
            // cout<<count<<endl;
            if(count == k){
                ans+= nums[i];
            }
        }
        return ans;
    }
};
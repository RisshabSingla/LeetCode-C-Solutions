class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<int> ans(n, 0);
        int index = n-1;
        for(int i =1; i<n; i+=2 ){
            ans[i] = nums[index];
            index--;
        }
        for(int i = 0; i<n; i+=2){
            ans[i] = nums[index];
            index--;
        }
        
        nums = ans;
    }
};
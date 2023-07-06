class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int size = nums.size();
        int ans = INT_MAX;
        int front = 0;
        int sum = 0;
        for(int i = 0; i<size; i++){
            sum+=nums[i];
            while(sum>=target){ 
                ans = min(ans, i - front+1);
                sum-=nums[front];
                front++;
            }
        }
        if(ans == INT_MAX){
            return 0;
        }
        return ans;
    }

};
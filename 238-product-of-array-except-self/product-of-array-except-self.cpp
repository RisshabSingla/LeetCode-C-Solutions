class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> front(size, 0);
        vector<int> rev(size, 0);
        int f= 1;
        int r = 1;
        front[0] = nums[0];
        rev[size-1] = nums[size-1];
        for(int i = 1; i<size-1; i++){
            front[i] = front[i-1]*nums[i];
            rev[size-i-1] = rev[size-i]*nums[size-i-1];
        }
        rev[0] = rev[1]*nums[0];
        front[size-1] = front[size-2]*nums[size-1];

        vector<int> ans(size);
        ans[0] = rev[1];
        ans[size-1] = front[size-2];
        for(int i = 1; i<size-1; i++){
            ans[i] = front[i-1]*rev[i+1];
        }
        return ans;


    }
};
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();
        vector<int> front(size,0);
        vector<int> back(size,0);
        front[0] = nums[0];
        back[size-1] = nums[size-1];
        for(int i = 1; i<size; i++){
            front[i] = front[i-1]*nums[i];
            back[size- i-1] = back[size-i]*nums[size-i-1];
        }

        vector<int> ans(size);
        ans[0] = back[1];
        ans[size-1] = front[size-2];
        for(int i = 1; i<size-1; i++){
            ans[i] = front[i-1]*back[i+1];
        }
        return ans;
    }
};
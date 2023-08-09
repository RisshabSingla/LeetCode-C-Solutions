class Solution {
public:
    bool checkValid(vector<int>&nums, int p, int diff){
        int count = 0;
        for(int i = 0; i<nums.size()-1 && count<p; i++){
            if(nums[i+1] - nums[i] <= diff){
                count++;
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int end = nums.back() - nums[0];
        int front = 0;
        while(front<end){
            int mid = front + (end - front)/2;
            if(checkValid(nums, p ,mid)){
                end = mid;
            }else{
                front = mid+1;
            }
        }
        return front;
    }
};
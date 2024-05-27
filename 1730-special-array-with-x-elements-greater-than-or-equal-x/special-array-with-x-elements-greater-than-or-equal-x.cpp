class Solution {
public:
    bool isPossible(vector<int>&nums, int n, int x){
        int index = n -  (lower_bound(nums.begin(), nums.end(), x)-nums.begin());
        // cout<<"index is: "<<index<<"\n";
        return index == x;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for(int i = 0; i<=n; i++){
            if(isPossible(nums, n, i)){
                return i;
            }
        }
        return -1;
    }
};
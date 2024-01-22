class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int> numbers;
        for(auto &i: nums){
            numbers[i]++;
        }
        int n = nums.size();
        vector<int> ans(2);
        for(int i = 1; i<=n; i++ ){
            if(numbers.count(i) == 0){
                ans[1] = i;
            }
            if(numbers[i] ==2){
                ans[0] = i;
            }
        }
        return ans;
    }
};
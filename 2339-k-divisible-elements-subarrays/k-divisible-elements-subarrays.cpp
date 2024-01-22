class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        int count = 0;
        int n = nums.size();
        set<vector<int>> done;
        for(int i = 0; i<n; i++){
            int c = 0;
            vector<int> arr;
            for(int j = i; j<n; j++){
                if(nums[j] % p == 0){
                    c++;
                }
                if(c > k){
                    break;
                }
                arr.push_back(nums[j]);
                if(done.count(arr) == 0){
                    done.insert(arr);
                    count++;
                }
            }
        }
        return count;
    }
};
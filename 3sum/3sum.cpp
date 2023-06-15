class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // Approach 1: Brute Force O(n^3)
        // sort(nums.begin(), nums.end());
        // set<vector<int>> ans;
        // int size = nums.size();
        // for(int i = 0; i<size; i++){
        //     for(int j = i+1; j<size; j++){
        //         for(int k = j+1; k<size; k++){
        //             if(nums[i]+nums[j]+nums[k] == 0){
        //                 vector<int> a;
        //                 a.push_back(nums[i]);
        //                 a.push_back(nums[j]);
        //                 a.push_back(nums[k]);
        //                 ans.insert(a);
        //             }
        //         }
        //     }
        // }
        // vector<vector<int>> f_ans(ans.begin(), ans.end());
        // return f_ans;


        // Approach 2: Using hashset O(n^2)
        // sort(nums.begin(), nums.end());
        // set<vector<int>> ans;
        // int size = nums.size();
        // for(int i = 0; i<size; i++){
        //     set<int> hashset;
        //     for(int j = i+1; j<size; j++){
        //         int elem = -(nums[i]+ nums[j]);
        //         if(hashset.find(elem)!= hashset.end()){
        //             vector<int> a = {nums[i],nums[j], elem};
        //             ans.insert(a);
        //         }
        //         hashset.insert(nums[j]); 
        //     }
        // }
        // vector<vector<int>> f_ans(ans.begin(), ans.end());
        // return f_ans;


        // Approach 3: Sorted 2 pointer
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int size = nums.size();
        for(int i = 0; i<size; i++){
            if(i >0  && nums[i] == nums[i-1]){
                continue;
            }
            int j = i+1;
            int k = size-1;
            while(j<k){
                int sum = nums[i]+ nums[j]+ nums[k];
                if(sum <0){
                    j++;
                }else if(sum>0){
                    k--;
                }else{
                    vector<int> triplet = {nums[i], nums[j], nums[k]};
                    ans.push_back(triplet);
                    j++;
                    k--;
                    while(j<k && j<size && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j<k && k>=0 && nums[k] == nums[k+1]){
                        k--;
                    }
                }
            }
        }
        return ans;



    }
};
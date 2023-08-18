class Solution {
public:
    int maxProduct(vector<int>& nums) {
        // Brute Force: O(n^3)
        // int max_product = INT_MIN;
        // int size = nums.size();
        // for(int i = 0; i<size; i++){
        //     for(int j = i; j<size; j++){
        //         int prod = 1;
        //         for(int k = i; k<=j; k++){
        //             prod*= nums[k];
        //         }
        //         max_product = max(max_product, prod);
        //     }
        // }
        // return max_product;

        // Brute Force Optimized: O(n^2)
        // int max_product = INT_MIN;
        // int size = nums.size();
        // for(int i = 0; i<size; i++){
        //     int prod = 1;
        //     for(int j = i; j<size; j++){
        //         prod*= nums[j];
        //         max_product = max(max_product, prod);
        //     }
        // }
        // return max_product;


        // Optimized Solution: O(n)

        int max_product = INT_MIN;
        int size = nums.size();
        // vector<int> prefix(size,1);
        // vector<int> suffix(size,1);
        // for(int i = )
        int prefix = 1;
        int suffix = 1;
        for(int i = 0; i<size; i++){
            if(prefix == 0){
                prefix = 1;
            }
            if(suffix == 0){
                suffix = 1;
            }
            prefix*= nums[i];
            suffix*= nums[size-1-i];
            max_product = max({max_product, suffix, prefix});
        }
        return max_product;





    }
};
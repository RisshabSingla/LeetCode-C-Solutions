class Solution {
public:
    static bool comp(vector<int>&a, vector<int>&b){
        if(a[0] == b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        // vector<int> ans;
        // int rows = nums.size();
        // for(int i = 0; i<rows; i++){
        //     int x = i;
        //     for(int y = 0; y<=i ; y++ , x--){
        //         if(y < nums[x].size()){
        //             ans.push_back(nums[x][y]);
        //         }
        //     }
        // }
        
        // for(int j = 1; j< nums[row-1].size(); j++){
            
        //     int x = row-1;
        //     while(x--){

        //     }
        // }
        // return ans;
        // This approach will not work 

        // Approach 1:
        // vector<vector<int>> numbers;
        // int rows = nums.size();
        // for(int i = 0; i<rows; i++){
        //     for(int j = 0; j<nums[i].size(); j++){
        //         numbers.push_back({(i+j), i, nums[i][j]});
        //     }
        // }

        // sort(numbers.begin(), numbers.end(), comp);
        // vector<int> ans;
        // for(int i = 0; i<numbers.size(); i++){
        //     ans.push_back(numbers[i][2]);
        //     // cout<<endl;
        // }
        // return ans;


        // Approach 2: 

        int rows = nums.size();
        map<int, vector<int>> mapping;
        for(int i = rows-1; i>=0; i--){
            for(int j = 0; j<nums[i].size(); j++){
                mapping[i+j].push_back(nums[i][j]);
            }
        }

        vector<int> ans;
        for(auto i: mapping){
            for(auto j: i.second){
                ans.push_back(j);
            }
        }
        return ans;
    }
};
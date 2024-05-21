class Solution {
public:
    string getBinary(int num , int size){
        string str = "";
        while(num >0){
            int l = num%2;
            str+=  to_string(l);
            num = num/2;
        }
        while(str.length() != size){
            str+= "0";
        }
        reverse(str.begin(), str.end());
        return str;

    }
    vector<vector<int>> subsets(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> ans;
        if(size == 0){
            return ans;
        }
        int possible = pow(2,size);
        for(int i = 0; i<possible; i++){
            string str = getBinary(i, size);
            vector<int> subset;
            for(int j = 0; j<size; j++){
                if(str[j] == '1'){
                    subset.push_back(nums[j]);
                }
            }
            ans.push_back(subset);
        }
        return ans;
    }
};
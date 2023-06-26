class Solution {
public:
    static bool comp(string a, string b){
        string str1 = a+b;
        string str2 = b+a;
        return str1>str2;
    }
    string largestNumber(vector<int>& nums) {
        int size = nums.size();
        if(size == 1){
            return to_string(nums[0]);
        }
        vector<string> numbers(size);
        for(int i = 0; i<size; i++){
            numbers[i] = to_string(nums[i]);
        }
        sort(numbers.begin(), numbers.end(), comp);
        if(numbers[0] == "0"){
            return "0";
        }
        string ans = "";
        for(int i = 0; i<size; i++){
            ans = ans + numbers[i];
            // cout<<numbers[i]<<" ";
        }
        return ans;
    }
};
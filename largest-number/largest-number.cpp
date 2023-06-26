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
        string ans = "";
        for(int i = 0; i<size; i++){
            // if(i == 0 && numbers[i] == "0"){
            //     continue;
            // }
            ans = ans + numbers[i];
            cout<<numbers[i]<<" ";
        }
        bool other = false;
        for(int i = 0; i<ans.length(); i++){
            if(ans[i] != '0'){
                other = true;
                break;
            }
        }
        if(!other){
            return "0";
        }
        return ans;
    }
};
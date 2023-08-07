class Solution {
public:
    int stoi(string str){
        int a = 0;
        for(int i = 0; i<str.length(); i++){
            if(str[i] == '1'){
                a = a*2 + 1;
            }else{
                a = a*2;
            }
        }
        // cout<<"Num is: "<<str<<" : "<<a<<endl;
        return a;
    }


    string itob(int a, int length){
        string str = "";
        while(a>0){
            int l = a%2;
            if(l){
                str = '1' + str;
            }else{
                str = '0' + str;
            }
            a = a/2;
        }
        while(str.length() != length){
            str = '0' + str;
        }
        return str;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int length = nums.size();
        unordered_set<int> numbers;
        for(int i = 0; i<length; i++){
            int a = stoi(nums[i]);
            numbers.insert(a);
        }

        for(int i = 0; i<pow(2, length); i++){
            if(numbers.find(i) == numbers.end()){
                // cout<<"i is: "<<i<<endl;
                return itob(i, length);
            }
        }
        return "";

    }
};
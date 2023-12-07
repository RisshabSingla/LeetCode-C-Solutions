class Solution {
public:
    string largestOddNumber(string num) {
        // cout<<"Num is: "<<num<<endl;
        // if(num.length()==0){
        //     return num;
        // }

        // long a = stol(num);
        // if(a%2 == 1){
        //     return num;
        // }

        // // return "";

        // long largest = INT_MIN;
        // for(int i = 1; i<num.length(); i++){
        //     string str1 = largestOddNumber(num.substr(i));
        //     string str2 = largestOddNumber(num.substr(0,i));
        //     long num1 = INT_MIN; 
        //     long num2 = INT_MIN;
        //     if(str1.length() != 0){
        //         num1 = stol(str1);
        //     }
        //     if(str2.length() != 0){
        //         num2 = stol(str2);
        //     }
        //     largest = max(num1,max(largest, num2));
        // }

        // if(largest == INT_MIN){
        //     return "";
        // }

        // return to_string(largest);
        int n = num.size();
        for(int i=n-1; i>=0; i--){
            if((num[i]-'0')%2 !=0) return num.substr(0, i+1);
        }
        return "";
    }
};
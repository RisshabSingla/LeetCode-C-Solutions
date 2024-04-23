class Solution {
public:
    string multiply(string num1, string num2) {
        string ans = "";
        int slen1 = num1.length();
        int slen2 = num2.length();
        int ansLength = 0;
        for(int i = 0; i<slen2; i++){
            string next = "";
            int carry = 0;
            int mul = num2[slen2-i-1]-'0';
            for(int j = slen1-1; j>=0; j--){
                int num = ((num1[j]-'0')*mul) + carry;
                if(num > 9){
                    carry = num/10;
                }else{
                    carry = 0;
                }
                num = num%10;
                next+= to_string(num);
            }
            if(carry != 0){
                next+= to_string(carry);
                carry = 0;
            }
            reverse(next.begin(), next.end());
            for(int k = 0; k<i; k++){
                next+= "0";
            }
            // cout<<"next is: "<<next<<"\n";
            int nextLength = next.length();
            for(int k = 0; k<(nextLength-ansLength); k++){
                ans = "0"+ ans;
            }
            // cout<<"ans1 is: "<<ans<<"\n";
            for(int k = nextLength-1; k>=0; k--){
                int num = (next[k]-'0') + (ans[k]-'0') + carry;
                // cout<<"Num is: "<<num<<"\n";
                if(num > 9){
                    carry = 1;
                }else{
                    carry = 0;
                }
                num%= 10;
                ans[k] = '0'+num;
                // cout<<"ans2 is: "<<ans<<" carry is: "<<carry<<"\n";
            }

            if(carry != 0){
                ans = to_string(carry) + ans;
                carry = 0;
            }
            ansLength = ans.length();
            // cout<<"ans is: "<<ans<<"\n";
        }
        bool other = false;
        for(int i = 0; i<ansLength; i++){
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
#include<cmath>

class Solution {
public:
    string convertToTitle(int columnNumber) {
        // string str = "";

        // int a = int(log(columnNumber)/ log(26));
        
        // int max_elem = 0;
        // for(int i = a-1; i>=0; i--){
        //     long num = pow(26,i);
        //     max_elem+= num*26;
        // }
        // if(max_elem > columnNumber){
        //     a--;
        // }

        // if(max_elem == columnNumber){
        //     for(int i = 0; i<a; i++){
        //        str+='Z';
        //     }
        //     return str;
        //     // cout<<endl;
        // }

        // long max_num = 0;
        // long mul = 0;
        // for(int i = a; i>=0; i--){
        //     long num = pow(26,i);
        //     cout<<"Num is: "<<num<<endl;
        //     for(int i = 1; i<=26; i++){
        //         long a = num*i;
        //         cout<<"a is: "<<a<<endl;
        //         cout<<"i is: "<<i<<endl;
        //         if(a>columnNumber){ 
        //             mul = i-1;
        //             break;
        //         }
        //         // if(a== columnNumber){
        //         //     mul = i-1;
        //         //     break;
        //         // }
                
        //         if(i == 26){
        //             mul = 26;
        //             break;
        //         }
        //     }
        //     cout<<"Value of mul is: "<<mul<<endl;
        //     char ch = mul + 'A' -1; 

        //     if(ch == '@'){
        //         ch = 'Z';
        //         columnNumber--;
        //     }
        //     str = str + ch;
        //     columnNumber -= num*mul;
        // }
        
        // return str;





        int rem = -1;
        string str = "";
        while(columnNumber>0){
            rem = columnNumber%26;
            columnNumber = columnNumber/26;
            char ch;
            if(rem!=0){
                ch = rem + 'A' -1;
            }else{
                ch = 'Z';
                columnNumber--;
            }
            str = ch + str;
        }
        return str;


    }
};
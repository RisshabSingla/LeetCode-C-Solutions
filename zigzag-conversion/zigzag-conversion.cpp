class Solution {
public:
    string convert(string str, int numRows) {
        int slen = str.length();
        if(slen == numRows){
            return str;
        }
        if(numRows == 1){
            return str;
        }
        int first_add = 2*numRows - 2;
        string ans = "";
        int second_add = 0;
        int s_index = 0;

        while(second_add <= first_add && s_index<slen){
           int second = second_add;
           int first = first_add - second;
           int index = s_index;
           ans += str[index];
           while(index<slen){
               if(first!= 0){
                   index+=first;
                   if(index<slen){
                       ans+=str[index];
                   }
                   
               }
               if(second!= 0){
                   index+=second;
                   if(index<slen){
                       ans+=str[index];
                   }
               }
           }
           s_index++;
           second_add+=2;
        }
        return ans;
        
    }
};
class Solution {
public:
    bool isDigit(char& ch){
        int a = ch - '0';
        if(a>= 0 && a<=9){
            return true;
        }
        return false;
    }
    string decodeAtIndex(string s, int k) {

        // Brute Force
        // string ans = "";
        // for(int i = 0; i<s.length(); i++){
        //     if(isDigit(s[i])){
        //         int repeat = s[i] - '0' -1;
        //         string add = ans;
        //         while(repeat>0){
        //             ans += add;
        //             repeat--;
        //         }
        //     }else{
        //         ans+= s[i];
        //     }
        //     // cout<<ans<<endl;
        //     if(ans.length() >= k){
        //         char ch = ans.at(k-1);
        //         string ans = "";
        //         ans.push_back(ch);
        //         return ans;
        //     }
        // }
        // return "";

        long long size = 0;
        int slen = s.length();
        for(int i = 0; i<slen; i++){
            char ch = s[i];
            if(isDigit(ch)){
                size*= (ch - '0');
            }else{
                size++;
            }
        }
        for(int i = slen-1; i>=0; i-- ){
            char ch = s[i];
            k = k% size;
            if( k == 0 && !isDigit(ch)){
                string ans = "";
                ans.push_back(ch);
                return ans;
            }
            if(isDigit(ch)){
                size/= (ch-'0');
            }else{
                size--;
            }   
        }
        return "";

    }
};
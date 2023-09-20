class Solution {
public:
    string convert(string &rec){

        string ans = "";
        char ch = rec[0];
        int count = 1;
        for(int i = 1;i<rec.length(); i++){
            if(ch != rec[i]){
                ans += to_string(count)+ char(ch);
                count = 0;
                ch = rec[i];
                // cout<<"Ans is: "<<ans<<endl;
            }
            count++;
        }
        ans += to_string(count)+ char(ch);
        // cout<<rec<<" : "<<ans<<endl;
        return ans;
    }
    // string helper(int n){
        
    // }
    string countAndSay(int n) {
        if(n == 1){
            return "1";
        }
        string rec = countAndSay(n-1);
        return convert(rec);
        // string ans = "";
        // n = 3322251;
        // int prev = n%10;
        // int count = 1;
        // n = n/10;
        // while(n!= 0){
        //     int p = n%10;
        //     if(p!= prev){
        //         ans = (to_string(count) +to_string(prev)) + ans;
        //         count = 0;
        //         prev = p;
        //         cout<<ans<<endl;
        //     }
        //     count++;
        //     n/=10;
        // }
        // ans = (to_string(count) +to_string(prev)) + ans;
        // return ans;
    }
};
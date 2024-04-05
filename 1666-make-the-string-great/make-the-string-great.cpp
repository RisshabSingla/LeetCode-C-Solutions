class Solution {
public:
    string makeGood(string& str) {
        int slen = str.length();
        // cout<<str<<"\n";
        while(true){
            bool change = false;
            for(int i = slen-1; i > 0; i--){
                if(str[i] == str[i-1] + 32 || str[i] + 32 == str[i-1]){
                    str.erase(str.begin() + i - 1);
                    str.erase(str.begin() + i - 1);
                    slen-=2;
                    change = true;
                }
            }
            // cout<<str<<"\n";
            if(!change){
                break;
            }
        }
        return str;
    }
};
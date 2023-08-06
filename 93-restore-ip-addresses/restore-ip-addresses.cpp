class Solution {
public: 
    int stoi(string str){
        int ans = 0;
        for(int i = 0; i<str.length(); i++){
            int a = str[i] - '0';
            ans = ans*10 + a;
        }
        return ans;
    }
    bool checkValid(string s){
        int index = 0;
        if(s[0] == '.'){
            return false;
        }
        vector<string> parts;
        int prev = 0;
        for(int i = 0; i<=s.length(); i++){
            if(s[i] == '.' || s[i] == '\0'){
                string str = s.substr(prev, i-prev);
                prev = i+1;
                if(str.length()>3 || (str[0] == '0' && str.length() > 1)){
                    return false;
                }
                int ip = stoi(str);
                if(ip>255){
                    return false;
                }
                parts.push_back(str);
            }
        }
        // cout<<"Parts are: ";
        // for(auto i : parts){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        
        return true;
    }
    void helper(string s, int placed, int index, vector<string> &ans){
        if(placed == 3){
            // cout<<"Index is: "<<index<<" String is: "<<s<<endl;
            // cout<<""
            if(checkValid(s)){
                ans.push_back(s);
            }
            return;
        }

        if(index == s.length()){
            return;
        }

        string str = s.substr(0, index) + '.' + s.substr(index);
        helper(str, placed+1, index+2, ans);
        helper(s, placed, index+1, ans);
    }

    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        helper(s, 0, 0, ans);
        return ans;
    }
};
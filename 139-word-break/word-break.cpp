class Solution {
public:
    bool helper2Memo(string word, vector<string> &dict, int index, unordered_map<int, bool> &dp){
        if(index == word.length()){
            dp[index] = true;
            return true;
        }

        if(dp.count(index)){
            return dp[index];
        }

        bool ans = false;
        for(int i = 0; i<dict.size(); i++){
            int ptr = index+1;
            char ch = word[index];
            if(dict[i][0] == ch){
                int j = 1;
                int len = dict[i].length();
                for(j = 1; j<len; j++){
                    if(dict[i][j] != word[ptr]){
                        break;
                    }
                    ptr++;
                }
                if(j == len){
                    // cout<<"Passing "<<dict[i]<<endl;
                    bool a =  helper2(word, dict, index+len);
                    if(a){
                        dp[index] = true;
                        return true;
                    }
                }
            }
        }
        dp[index] = false;
        return false;
    }



    bool helper2(string word, vector<string> &dict, int index){
        if(index == word.length()){
            return true;
        }
        bool ans = false;
        for(int i = 0; i<dict.size(); i++){
            int ptr = index+1;
            char ch = word[index];
            if(dict[i][0] == ch){
                int j = 1;
                int len = dict[i].length();
                for(j = 1; j<len; j++){
                    if(dict[i][j] != word[ptr]){
                        break;
                    }
                    ptr++;
                }
                if(j == len){
                    // cout<<"Passing "<<dict[i]<<endl;
                    bool a =  helper2(word, dict, index+len);
                    if(a){
                        return true;
                    }
                    ans = ans || a;
                }
            }
        }
        return ans;
        // return false;
    }


    bool helper(string word, string curr, vector<string> &dict, int index){
        if(index == word.length()){
            // cout<<"Curr is: "<<curr<<endl;
            for(auto i : dict){
                if(i == curr){
                    // cout<<"Found the word: "<<curr<<endl;
                    return true;
                }
            }
            // if(dict.find(curr) != dict.end()){
            //     return true;
            // }
            return false;
        }
        bool a = false;
        bool b = false;

        bool found = false;
        for(auto i: dict){
            if(i == curr){
                found = true;
                break;
            }
        }

        if(found){
            // cout<<"Found the word: "<<curr<<endl;
            string str = word.substr(index, 1);
            // using the current word
            // cout<<"Inside found str is: "<<str<<endl;
            a = helper(word, str, dict, index+1);
        }
        string str = curr + char(word[index]);
        b = helper(word, str , dict, index+1);

        return a||b;
    }


    int findMatch(string str, string word, int index){
        for(int i = 0; i<word.length(); i++){
            if(index+i == str.length()){
                return 0;
            }
            if(str[index+i] != word[i]){
                return 0;
            }
        }
        return word.length();
    }

    bool helperDP(string str, vector<string> &dict){

        int len = str.length();
        vector<bool> dp(len+1, false);
        dp[len] = true;

        int size = dict.size();

        for(int i = len-1; i>=0; i--){
            
            for(int index = 0; index<size; index++){
                // cout<<"Checking for: "<<dict[index]<<endl;
                if(str[i] == dict[index][0]){
                    // cout<<"Checking for: "<<dict[index]<<endl;
                    int matched = findMatch(str, dict[index], i);
                    if(matched != 0){
                        dp[i] = dp[i] || dp[i+matched];
                        if(dp[i]){
                            cout<<"Set "<<i<<" with: "<<dict[index]<<endl;
                        }
                    }
                }
            }
        }
        for(auto i : dp){
            cout<<i<<" ";
        }
        cout<<endl;
        return dp[0];
    }

    bool wordBreak(string s, vector<string>& wordDict) {
        // return helper(s,"",wordDict, 0);
        // unordered_map<int, bool> dp;
        // return helper2Memo(s, wordDict, 0, dp);


        return helperDP(s, wordDict);

        // return helper2(s, wordDict, 0);
    }
};
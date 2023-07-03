class Solution {
public:
    bool buddyStrings(string s, string goal) {
        // int c=0;
        // for(int i=0;i<goal.length();i++){
        //     if(s[i]==goal[i]){
        //         c++;
        //     }
        // }
        // if(c==goal.length()){
        //     return true;
        // }
        // if(s.length() == 2){
        //     char a = s[0];
        //     s[0] = s[1];
        //     s[1] = a;
        //     if(s == goal){
        //         return true;
        //     }
        //     return false;
        // }

        if(s == goal){
            // map<char, vector<int>> position;
            map<char,int>position;
            for(int i = 0; i<s.length(); i++){
                // position[s[i]].push_back(i);
                position[s[i]]++;
            }
            for(auto i: position){
                if(i.second>1){
                    return true;
                }
            }
            return false;
        }

        int count=0;
        vector<char>v1,v2;
        if(s.length()==goal.length()){
            for(int i=0;i<s.length();i++){
                if(s[i]!=goal[i]){
                    v1.push_back(s[i]);
                    v2.push_back(goal[i]);
                    count++;
                }
            }
            sort(v1.begin(),v1.end());
            sort(v2.begin(),v2.end());
            if(count==2){
                if((v1[0]==v2[0])&& v1[1]==v2[1]){
                    return true;
                }
            }
        }
        return false;
        
    }
};
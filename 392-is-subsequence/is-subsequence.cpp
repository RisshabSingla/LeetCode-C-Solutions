class Solution {
public:
    bool isSubsequence(string t, string s) {
        int index = 0;
        if(t.length() == 0){
            return true;
        }
        for(int i = 0; i<s.length(); i++){
            if(t[index] == s[i]){
                if(index ==t.length()-1){
                    return true;    
                }
                index++;
            }
        }
        
        return false;

    }
};
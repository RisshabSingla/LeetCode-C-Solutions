class Solution {
public:
    int max_len = 0;
    bool isValid(string&str, string& s){
        vector<int> freq(26,0);
        // cout<<"Checking: "<<str<<" and "<<s<<"\n";
        for(int i = 0; i<str.length(); i++){
            freq[str[i]-'a']++;
        }
        for(int i = 0; i<s.length(); i++){
            if(freq[s[i]-'a'] > 0){
                return false;
            }
            freq[s[i]-'a']++;
        }
        return true;
    }
    void recursive(vector<string>& arr, string str, int index, int n){
        // cout<<"Index: "<<index<<" str: "<<str<<"\n";
        if(index == n){
            if(max_len < str.length()){
                max_len = str.length();
            }
            return;
        }
        recursive(arr, str, index+1, n);
        if(isValid(str, arr[index])){
            // cout<<"isValid: "<<arr[index]<<"\n";
            // str+= "_";
            str+= arr[index];
            recursive(arr, str, index+1, n);
        }
    }
    int maxLength(vector<string>& arr) {
        string str = "";
        int n = arr.size();
        recursive(arr, str ,0,n);
        return max_len;
    }
};
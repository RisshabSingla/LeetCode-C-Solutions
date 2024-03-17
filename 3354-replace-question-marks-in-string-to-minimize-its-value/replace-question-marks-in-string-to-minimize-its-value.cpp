class Solution {
public:
    string minimizeStringValue(string& str) {
        vector<int> freq(26,0);
        int slen = str.length();
        for(int i = 0; i<slen; i++){
            if(str[i] == '?'){
                continue;
            }
            freq[str[i]-'a']++;
        }
        vector<char> in;
        for(int i = 0; i<slen; i++){
            int index = -1;
            int count = INT_MAX;
            if(str[i] == '?'){
                for(int j = 0; j<26; j++){
                    if(count > freq[j]){
                        count = freq[j];
                        index = j;
                    }
                }
                in.push_back(char('a'+index));
                freq[index]++;
            }
        }
        sort(in.begin(), in.end());
        int index = 0;
        for(int i = 0; i<slen; i++){
            if(str[i] == '?'){
                str[i] = in[index];
                index++;
            }
        }
        return str;
    }
};
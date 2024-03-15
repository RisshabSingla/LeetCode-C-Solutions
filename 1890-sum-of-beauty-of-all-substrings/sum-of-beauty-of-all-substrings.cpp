class Solution {
public:
    int calcBeauty(string&str, int start, int end){
        vector<int> freq(26, 0);
        int mini = INT_MAX;
        int maxi = 0;
        for(int i = start; i<=end; i++){
            freq[str[i]-'a']++;
        }
        for(int i = 0; i<26; i++){
            if(freq[i] == 0){
                continue;
            }
            mini = min(mini, freq[i]);
            maxi = max(maxi, freq[i]);
        }
        return maxi-mini;
    }

    int calcBeauty(vector<int>&arr1, vector<int>&arr2){
        int mini = INT_MAX;
        int maxi = 0;
        for(int i = 0; i<26; i++){
            int count = arr2[i]-arr1[i];
            if(count == 0){
                continue;
            }
            mini = min(mini, count);
            maxi = max(maxi, count);
        }
        return maxi-mini;
    }
    int beautySum(string &s) {
        int sum = 0;
        int slen = s.length();
        vector<vector<int>> prefix(slen+1);
        vector<int> curr(26,0);
        prefix[0] = curr;
        for(int i = 0; i<slen; i++){
            curr[s[i]-'a']++;
            prefix[i+1] = curr;
        }

        for(int i = 1; i<=slen; i++){
            for(int j = i+1; j<=slen; j++){
                sum+= calcBeauty(prefix[i-1], prefix[j]);
            }
        }
        return sum;
    }
};
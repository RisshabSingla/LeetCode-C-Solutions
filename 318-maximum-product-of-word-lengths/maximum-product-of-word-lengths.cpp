class Solution {
public:
    int findNumber(string& word){
        int number = 0;
        for(char ch: word){
            number = number | (1<<(ch-'a'+1));
        }
        return number;
    }
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> arr(n, 0);
        for(int i = 0; i<n; i++){
            arr[i] = findNumber(words[i]);
        }
        int maxi = 0;
        for(int i = 0; i<n; i++){
            for(int j = i+1; j<n; j++){
                if((arr[i] & arr[j]) == 0){
                    int len = words[i].length() * words[j].length();
                    maxi = max(maxi, len);
                }
            }
        }
        return maxi;
    }
};
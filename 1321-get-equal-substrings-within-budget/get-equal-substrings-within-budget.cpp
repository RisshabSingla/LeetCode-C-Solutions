class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int slen = s.length();
        int front  = 0;
        int current = 0;
        int maxi = 0;
        for(int back = 0; back<slen; back++){
            current+= abs(s[back]-t[back]);
            while(current > maxCost){
                current-= abs(s[front]-t[front]);
                front++;
            }
            maxi = max(maxi, back-front+1);
        }
        return maxi;
    }
};
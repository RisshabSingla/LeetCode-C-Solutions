class Solution {
public:
    string frequencySort(string s) {
        sort(s.begin(), s.end());
        char prev = s[0];
        int count = 0;
        int slen = s.length();
        priority_queue<pair<int,char>> pq;
        for(int i = 0; i<=slen; i++){
            if(i == slen || s[i]!= prev){
                pq.push({count, prev});
                count = 1;
                prev = s[i];
            }else{
                count++;
            }
        }

        string ans = "";
        while(!pq.empty()){
            pair<int,char> p = pq.top();
            pq.pop();
            ans += string(p.first, p.second);
        }
        return ans;

    }
};
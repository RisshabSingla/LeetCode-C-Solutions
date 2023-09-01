class Solution {
public:
    vector<int> countBits(int n) {
        // vector<int> ans;
        // for(int i = 0; i<=n; i++){
        //     int bits = __builtin_popcount(i);
        //     ans.push_back(bits);
        // }
        // return ans;

        vector<int> ans;
        ans.push_back(0);
        for(int i = 1; i<=n; i++){
            int j = i;
            int count = 0;
            while(j>0){
                int last = j%2;
                if(last == 1){
                    count++;
                }
                j = j/2;
            }
            ans.push_back(count);
        }

        return ans;



    }
};
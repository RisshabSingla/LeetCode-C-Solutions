class Solution {
public:
    vector<string> calculateAns(int n){
        if(n == 1){
            return {"1", "0"};
        }
        vector<string> ans = calculateAns(n-1);
        int size = ans.size();
        for(int i = 0; i<size; i++){
            if(ans[i].back() == '0'){
                ans[i].push_back('1');
            }else{
                string str = ans[i] + '1';
                ans.push_back(str);
                ans[i].push_back('0');
            }
        }
        return ans;

    }
    vector<string> validStrings(int n) {
        return calculateAns(n);
    }
};
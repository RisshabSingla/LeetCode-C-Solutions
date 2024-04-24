class Solution {
public:
    void populateAns(int num, vector<int> &ans, int number){
        if(num != 0 && num <= number){
            ans.push_back(num);
        }
        if(num >= number){
            return;
        }
        // num = num*10;
        // if(num <= number){
        //     ans.push_back(num);
        // }
        for(int i = 0; i<10; i++){
            populateAns(num*10 + i,ans, number);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        int limit = n;
        if(limit > 10){
            limit = 9;
        }
        for(int i = 1; i<10; i++){
            populateAns(i, ans, n);
        }
        return ans;
    }
};
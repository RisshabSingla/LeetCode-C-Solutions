class Solution {
public:
    void populateAns(int num, vector<int> &ans, int number){
        if(num <= number){
            ans.push_back(num);
        }else{
            return;
        }
        for(int i = 0; i<10; i++){
            populateAns(num*10 + i,ans, number);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i = 1; i<10; i++){
            populateAns(i, ans, n);
        }
        return ans;
    }
};
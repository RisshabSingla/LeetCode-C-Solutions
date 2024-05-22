class Solution {
public:
    vector<vector<string>>ans;
    bool isPalindrome(string&str, int front, int back){
        while(front<back){
            if(str[front] != str[back]){
                return false;
            }
            front++;
            back--;
        }
        return true;
    }
    void findAns(string&str, int index, int n, vector<string>& curr){
        if(index == n){
            ans.push_back(curr);
            return;
        }
        for(int i = index; i<n; i++){
            if(isPalindrome(str, index, i)){
                curr.push_back(str.substr(index, i-index+1));
                findAns(str, i+1, n, curr);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> curr;
        findAns(s, 0, s.length(), curr);
        return ans;
    }
};
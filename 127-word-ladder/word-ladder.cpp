class Solution {
public:
    bool checkValid(string &str1, string &str2){
        int diff = 0;
        for(int i = 0; i<str1.length(); i++){
            if(str1[i] != str2[i]){
                diff++;
            }
            if(diff>1){
                return false;
            }
        }
        return diff <= 1;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        auto itr = find(wordList.begin(), wordList.end(), endWord) ;
        if(itr == wordList.end()){
            return 0;
        }
        int index = itr - wordList.begin();
        queue<pair<string,int>> q;
        int n = wordList.size();
        vector<bool> visited(n, false);
        visited[index] = true;
        q.push({endWord, 1});
        // wordList.push_back(beginWord);
        while(!q.empty()){
            pair<string,int> p = q.front();
            q.pop();
            // cout<<p.first<<endl;
            if(checkValid(p.first, beginWord)){
                return p.second+1;
            }
            for(int i = 0; i<n; i++){
                if(!visited[i] && checkValid(p.first, wordList[i])){
                    // cout<<"Pushing: "<<wordList[i]<<" "<<p.second+1<<endl;
                    q.push({wordList[i], p.second+1});
                    visited[i] = true;
                }
            }
        }
        return 0;
    }
};
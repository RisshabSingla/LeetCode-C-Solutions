class Solution {
public:
    int size = 0;
    bool checkValid(string& str1, string& str2) {
        int diff = 0;
        for (int i = 0; i < str1.length(); i++) {
            if (str1[i] != str2[i]) {
                diff++;
            }
            if (diff > 1) {
                return false;
            }
        }
        return diff == 1;
    }

    void dfs(string& beginWord, string& endWord, vector<string>& curr,
             set<vector<string>>& ans, vector<bool>& visited,
             unordered_map<string, vector<int>>& diffOne,
             vector<string>& wordList) {

        if (beginWord == endWord) {
            if (size == 0) {
                ans.insert(curr);
                size = curr.size();
            }
            if (size != 0 && curr.size() < size) {
                ans.clear();
                ans.insert(curr);
                size = curr.size();
            }

            if (curr.size() == size) {
                ans.insert(curr);
            }
            return;
        }
        for (auto& i : diffOne[beginWord]) {
            if (!visited[i]) {
                if (size != 0 && curr.size() + 1 > size) {
                    continue;
                }
                curr.push_back(wordList[i]);
                visited[i] = true;
                dfs(wordList[i], endWord, curr, ans, visited, diffOne,
                    wordList);
                visited[i] = false;
                curr.pop_back();
            }
        }
    }

    vector<vector<string>> bfs(string& beginWord, string& endWord,
                               unordered_map<string, vector<int>>& diffOne,
                               vector<string>& wordList, int n) {
        // storing the whole string in sequence in bfs queue
        vector<vector<string>> ans;
        queue<vector<string>> q;
        vector<bool> visited(n, false);
        q.push({beginWord});
        while (!q.empty()) {
            int size = q.size();
            vector<int> vis;
            for (int i = 0; i < size; i++) {
                vector<string> front = q.front();
                q.pop();
                if (front.back() == endWord) {
                    ans.push_back(front);
                    continue;
                }
                for (auto& i : diffOne[front.back()]) {
                    if (!visited[i]) {
                        front.push_back(wordList[i]);
                        q.push(front);
                        front.pop_back();
                        vis.push_back(i);
                    }
                }
            }
            for(auto &i: vis){
                visited[i] = true;
            }
        }
        return ans;
    }




    vector<vector<string>> bfs2(string& beginWord, string& endWord,
                               unordered_map<string, vector<int>>& diffOne,
                               vector<string>& wordList, int n,int beginIndex) {
        // storing indexes in bfs queue 
        vector<vector<int>> ans;
        queue<vector<int>> q;
        vector<bool> visited(n, false);
        q.push({beginIndex});
        while (!q.empty()) {
            int size = q.size();
            vector<int> vis;
            for (int i = 0; i < size; i++) {
                vector<int> front = q.front();
                q.pop();
                if (wordList[front.back()] == endWord) {
                    ans.push_back(front);
                    continue;
                }
                for (auto& i : diffOne[wordList[front.back()]]) {
                    if (!visited[i]) {
                        front.push_back(i);
                        q.push(front);
                        front.pop_back();
                        vis.push_back(i);
                    }
                }
            }
            for(auto &i: vis){
                visited[i] = true;
            }
        }

        vector<vector<string>> fans;
        for(auto &i: ans){
            vector<string> curr;
            for(auto &j: i){
                curr.push_back(wordList[j]);
            }
            fans.push_back(curr);
        }
        return fans;
    }

    vector<vector<string>> bfs3(string& beginWord, string& endWord,
                               vector<string>& wordList, int n,int beginIndex) {
        // storing indexes in bfs queue 
        vector<vector<int>> ans;
        queue<vector<int>> q;
        vector<bool> visited(n, false);
        q.push({beginIndex});
        while (!q.empty()) {
            int size = q.size();
            vector<int> vis;
            bool found = false;
            for (int i = 0; i < size; i++) {
                vector<int> front = q.front();
                q.pop();
                if (wordList[front.back()] == endWord) {
                    ans.push_back(front);
                    found = true;
                    continue;
                }
                // for (auto& i : diffOne[wordList[front.back()]]) {
                //     if (!visited[i]) {
                //         front.push_back(i);
                //         q.push(front);
                //         front.pop_back();
                //         vis.push_back(i);
                //     }
                // }
                for(int i = 0; i<n; i++){
                    if(!visited[i] && checkValid(wordList[front.back()], wordList[i])){
                        front.push_back(i);
                        q.push(front);
                        front.pop_back();
                        vis.push_back(i);
                    }
                }
            }
            for(auto &i: vis){
                visited[i] = true;
            }
            if(found){
                break;
            }
        }

        vector<vector<string>> fans;
        for(auto &i: ans){
            vector<string> curr;
            for(auto &j: i){
                curr.push_back(wordList[j]);
            }
            fans.push_back(curr);
        }
        return fans;
    }
    // opulateAns(curr, ans, order);
    void populateAns(string &word, vector<string>&curr, vector<vector<string>> &ans, unordered_map<string, int>&order, string&beginWord){
        // cout<<"Curr is: ";
        // for(auto &i: curr){
        //     cout<<i<<' ';
        // }
        // cout<<"\n";
        if(word == beginWord){
            ans.push_back(curr);
            return;
        }
        int len = beginWord.length();
        int val = order[word];
        for(int i = 0; i<len; i++){
            char original = word[i];
            for(char ch = 'a'; ch<= 'z' ; ch++){
                word[i] = ch;
                if(order.count(word) && order[word] + 1 == val){
                    curr.push_back(word);
                    populateAns(word, curr, ans, order, beginWord);
                    curr.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findAns(string &beginWord, string &endWord,
                                       vector<string>& wordList){
        unordered_map<string, int> order;
        unordered_set<string> words(wordList.begin(),wordList.end());
        queue<string> q;
        q.push(beginWord);
        order[beginWord] = 0;
        words.erase(beginWord);
        int len = beginWord.length();
        while(!q.empty()){
            string front = q.front();
            q.pop();
            if(front == endWord){
                break;
            }
            int val = order[front];
            for(int i = 0; i<len; i++){
                char original = front[i];
                for(char ch = 'a'; ch<= 'z' ; ch++){
                    front[i] = ch;
                    if(words.count(front)){
                        words.erase(front);
                        q.push(front);
                        order[front] = val+1;
                    }
                }
                front[i] = original;
            }
        }

        vector<vector<string>> ans;
        if(order.count(endWord)){
            vector<string> curr;
            curr.push_back(endWord);
            populateAns(endWord,curr, ans, order, beginWord);
            for(auto &i: ans){
                reverse(i.begin(), i.end());
            }
        }

        return ans;


    }


    vector<vector<string>> findLadders(string beginWord, string endWord,
                                       vector<string>& wordList) {
        auto itr = find(wordList.begin(), wordList.end(), endWord);
        if (itr == wordList.end()) {
            return {};
        }

        // int beginIndex = -1;
        // int n = wordList.size();
        // auto itr2 = find(wordList.begin(), wordList.end(), beginWord);
        // if(itr2 == wordList.end()){
        //     wordList.push_back(beginWord);
        //     beginIndex = n;
        //     n++;
        // }else{
        //     beginIndex = itr2 - wordList.begin();
        // }
        

        // indexes of strings that have one difference with some string
        // unordered_map<string, vector<int>> diffOne;
        
        // for (int i = 0; i < n; i++) {
        //     for (int j = 0; j < n; j++) {
        //         if (checkValid(wordList[i], wordList[j])) {
        //             diffOne[wordList[i]].push_back(j);
        //         }
        //     }
        // }

        // if (!diffOne.count(beginWord)) {
        //     for (int i = 0; i < n; i++) {
        //         if (checkValid(wordList[i], beginWord)) {
        //             diffOne[beginWord].push_back(i);
        //         }
        //     }
        // }

        // if (!diffOne.count(beginWord)) {
        //     // no string with difference one with beginWord
        //     return {};
        // }

        // Using DFS
        // vector<string> curr;
        // curr.push_back(beginWord);
        // vector<bool> visited(n, false);
        // set<vector<string>> ans;
        // dfs(beginWord, endWord, curr, ans, visited, diffOne, wordList);
        // vector<vector<string>> fans(ans.begin(), ans.end());
        // return fans;

        // Using BFS
        // return bfs(beginWord, endWord, diffOne, wordList, n);
        // return bfs2(beginWord, endWord, diffOne, wordList, n, beginIndex);
        // return bfs3(beginWord, endWord, wordList, n, beginIndex);


        return findAns(beginWord, endWord, wordList);
    }
};
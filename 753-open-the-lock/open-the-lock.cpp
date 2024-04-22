class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> visited;
        for(auto &i: deadends){
            visited.insert(i);
        }
        queue<string> q;
        if(!visited.count("0000")){
            q.push("0000");
            q.push("");
        }
        int level = 0;
        while(!q.empty()){
            string front = q.front();
            q.pop();
            if(front == target){
                return level;
            }
            if(front == ""){
                if(!q.empty()){
                    q.push("");
                }
                level++;
                continue;
            }
            for(int i = 0;i<4; i++){
                int num = front[i] -'0';
                front[i] = char('0' + (num+1)%10);
                if(!visited.count(front)){
                    visited.insert(front);
                    q.push(front);
                }
                front[i] = char('0' + (num+9)%10);
                if(!visited.count(front)){
                    visited.insert(front);
                    q.push(front);
                }
                front[i] = char('0' + num);
            }
        }
        return -1;
    }
};
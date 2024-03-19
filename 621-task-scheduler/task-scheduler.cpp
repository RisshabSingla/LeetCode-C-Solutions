class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> freq(26,0);
        for(int i = 0; i<tasks.size(); i++){
            freq[tasks[i]-'A']++;
        }
        int time = 0;
        priority_queue<int>pq;
        for(int i = 0; i<26; i++){
            if(freq[i] != 0){
                pq.push(freq[i]);
            }
        }

        while(!pq.empty()){
            vector<int> temp;
            for(int i = 0; i<n+1; i++){
                if(pq.empty()){
                    break;
                }
                int top = pq.top();
                pq.pop();
                top--;
                temp.push_back(top);
            }
            for(int &i: temp){
                if(i > 0){
                    pq.push(i);
                }
            }
            if(pq.empty()){
                time+= temp.size();
            }else{
                time+= (n+1);
            }
        }
        return time;
    }
};
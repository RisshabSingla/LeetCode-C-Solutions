class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        sort(deck.begin(), deck.end());
        queue<int> q;
        for(int i = 0; i<n; i++){
            q.push(i);
        }
        int index = 0;
        vector<int> ans(n);
        while(!q.empty()){
            int front = q.front();
            q.pop();
            ans[front] = deck[index];
            index++;
            if(q.empty()){
                break;
            }
            int other = q.front();
            q.pop();
            q.push(other);
        }
        return ans;
    }
};
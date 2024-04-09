class Solution {
public:
    int timeRequiredToBuy(vector<int>& arr, int k) {
        arr[k] = -arr[k];
        queue<int> q;
        for(auto &i: arr){
            q.push(i);
        }
        int count = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            count++;
            if(front == -1){
                break;
            }
            if(front < 0){
                front++;
            }else{
                front--;
            }
            
            if(front != 0){
                q.push(front);
            }
        }
        return count;
    }
};
class Solution {
public:
    bool performBFS(int n, vector<int>& leftChild, vector<int>& rightChild, int first){
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(first);
        visited[first] = true;
        while(!q.empty()){
            int index = q.front();
            // visited[index] = true;
            q.pop();
            int lft = leftChild[index];
            int rgt = rightChild[index];
            // cout<<"index is: "<<index<<endl;
            if(lft != -1){
                if(visited[lft]){
                    return false;
                }
                visited[lft] = true;
                // cout<<"Pushing: "<<lft<<endl;
                q.push(lft);
            }
            if(rgt != -1){
                if(visited[rgt]){
                    return false;
                }
                visited[rgt] = true;
                // cout<<"Pushing: "<<rgt<<endl;
                q.push(rgt);
            }
        }
        for(int i = 0; i<n; i++){
            if(!visited[i]){
                return false;
            }
        }
        return true;
    }
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        bool ans = false;
        for(int i = 0; i<n; i++){
            bool a = performBFS(n, leftChild, rightChild, i);
            if(ans && a){
                return false;
            }
            if(a){
                ans = true;
            }
        }
        return ans;
    }
};
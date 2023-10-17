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


    bool isValidBFS(int n, vector<int>& leftChild, vector<int>& rightChild, int root){
vector<bool> visited(n, false);
        queue<int> q;
        q.push(root);
        visited[root] = true;
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
        // bool ans = false;
        // for(int i = 0; i<n; i++){
        //     bool a = performBFS(n, leftChild, rightChild, i);
        //     if(ans && a){
        //         return false;
        //     }
        //     if(a){
        //         ans = true;
        //     }
        // }
        // return ans;


        vector<bool> childCount(n, false);
        for (auto child : leftChild) {
            if (child != -1)
                childCount[child] = true;
        }

        for (auto child : rightChild) {
            if (child != -1) {
                if (childCount[child]) 
                    return false;

                childCount[child] = true; 
            }
        }

        int root = -1; 
        for (int i = 0; i < n; ++i) {
            if (!childCount[i]) {
                if (root == -1)
                    root = i; 
                else
                    return false; 
            }
        }

        if (root == -1)
            return false;

        return isValidBFS(n, leftChild, rightChild, root);
    }
};
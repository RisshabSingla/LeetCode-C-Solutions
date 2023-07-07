class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // Approach 1: Direct Rotation
        
        // int left = 0;
        // int right = matrix[0].size()-1;
        // int top = 0;
        // int bottom = matrix.size()-1;
        // while(left<right && top<bottom){
        //     int diff = right-left;
        //     for(int i = 0; i<diff; i++){
        //         int a = matrix[top][left+i];
        //         matrix[top][left+i] = matrix[bottom-i][left];
        //         matrix[bottom-i][left] = matrix[bottom][right-i];
        //         matrix[bottom][right-i] = matrix[top+i][right];
        //         matrix[top+i][right] = a;
        //     }
        //     top++;
        //     bottom--;
        //     right--;
        //     left++;
        // }

        // Approach 2: Transpose and reverse
        int size = matrix.size();
        // transpose
        for(int i = 0; i<size; i++){
            for(int j = i+1; j<size; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // cout<<"Matrix is: "<<endl;
        // for(auto i: matrix){
        //     for(auto j : i){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }
        // cout<<endl;
        for(int i = 0; i<size; i++){
            int front = 0;
            int last = size-1;
            while(front<last){
                swap(matrix[i][front], matrix[i][last]);
                front++;
                last--;
            }
        }
        


    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans;
        vector<int> a;
        a.push_back(1);
        // ans.push_back(a);
        if(rowIndex == 0){
            return a;
        }

        vector<int> row1;
        row1.push_back(1);
        row1.push_back(1);
        ans.push_back(row1);
        if(rowIndex == 1){
            return ans[0];
        }

        // vector<int> row2;
        // row2.push_back(1);
        // // row2.push_back(2);
        // row2.push_back(1);
        // ans.push_back(row2);
        // if(rowIndex == 2){
        //     return ans[1];
        // }


        for(int i = 1;i<=rowIndex; i++){
            vector<int> r;
            r.push_back(1);
            for(int j =1; j<i; j++){
                int num = ans[i-1][j-1] + ans[i-1][j];
                r.push_back(num);
            } 
            r.push_back(1);
            ans.push_back(r);
        }

        return ans[rowIndex];
    }
};
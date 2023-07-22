class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if(k == 0){
            return 1.00;
        }
        vector<vector<double>> prev(n, vector<double>(n,0.00));
        // vector<vector<double>> curr;
        prev[row][column] = 1.00;
        vector<vector<int>> possible = {
            {1,2}, {-1,2}, {1,-2},{-1,-2}, 
            {2,1}, {-2,1}, {2,-1},{-2,-1}
                                };
        for(int t = 0; t<k; t++){
            vector<vector<double>> curr(n, vector<double>(n,0.00));
            for(int i = 0; i<n; i++){
                for(int j = 0; j<n; j++){
                    for(int dir = 0; dir<8; dir++){
                        int prevI = i - possible[dir][0];
                        int prevJ = j - possible[dir][1];
                        if(prevI>=0 && prevI<n && prevJ>=0 && prevJ < n){
                            curr[i][j] += (prev[prevI][prevJ]/8.0);
                        }
                    }
                }
            }
            // cout<<"Matrix is: "<<endl;
            // for(auto i: curr){
            //     for(auto j : i){
            //         cout<<j<<" ";
            //     }
            //     cout<<endl;
            // }
            // cout<<endl;
            prev = curr;
        }
        double ans = 0;
        for(int i = 0; i<n;i++){
            for(int j = 0; j<n; j++){
                ans+= prev[i][j];
            }
        }
        return ans;
    }
};
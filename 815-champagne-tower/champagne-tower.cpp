class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        // if(poured == 1){
        //     if(query_row == 1){
        //         return 1.00;
        //     }
        //     return 0.00;
        // }
        vector<double> row(1,poured);
        for(int i = 0; i<=query_row; i++){
            vector<double> next_row(i+2, 0);
            for(int j = 0; j<=i; j++){
                if(row[j] >= 1){
                    next_row[j]+= (row[j]-1)/2.0;
                    next_row[j+1]+= (row[j]-1)/2.0;
                    row[j] = 1;
                }
            }
            if(i!= query_row){
                row = next_row;
            }
        }

        return row[query_glass];

    }
};
class Solution {
public:
    // int findArea(int n, int m, int hBar, int vBar){
    //     int side1 = min(hBar-1, vBar-1);
    //     int side2 = min(m+2-vBar, hBar-1);
    //     int side3 = min(n+2-hBar, vBar-1);
    //     int side4 = min(m+2-vBar, n+2-hBar);
    //     int maxi = max({side1, side2, side3, side4});
    //     // cout<<"hBar: "<<hBar<<" vBar: "<<vBar<<" Side1: "<<side1<<" Side2: "<<side2<<" Side3: "<<side3<<" Side4: "<<side4<<"\n";
    //     return maxi*maxi;
    // }
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        int hBarSize = hBars.size();
        int vBarSize = vBars.size();

        sort(hBars.begin(), hBars.end());
        sort(vBars.begin(), vBars.end());


        // Approach 1: Removing all the bars & finding area -> MLE
        // vector<int> verBars;
        // vector<int> horBars;

        // unordered_set<int> s;
        // for(int i = 0; i<hBarSize; i++){
        //     s.insert(hBars[i]);
        // }
        // for(int i = 2; i<=n+2; i++){
        //     if(!s.count(i)){
        //         horBars.push_back(i);
        //     }
        // }

        // s.clear();
        // for(int i = 0; i<vBarSize; i++){
        //     s.insert(vBars[i]);
        // }
        // for(int i = 2; i<=m+2; i++){
        //     if(!s.count(i)){
        //         verBars.push_back(i);
        //     }
        // }

        // hBarSize = horBars.size();
        // vBarSize = verBars.size();
        // int maxi = 0;
        // int prevH = 1;
        // int prevV = 1;
        // for(int i = 0; i<vBarSize; i++){
        //     for(int j = 0; j<hBarSize; j++){
        //         int side = min(verBars[i] - prevV, horBars[j] - prevH);
        //         int area = side*side;
        //         // cout<<"Vert: "<<verBars[i]<<" Hort: "<<horBars[j]<<" area: "<<area<<"\n";
        //         maxi = max(area, maxi);
        //         prevH = horBars[j];
        //     }
        //     prevV = verBars[i];
        //     prevH = 1;
        // }
        // return maxi;


        // Approach 2: Finding consecutive removals possible

        int prev = 1;
        int consH = 0;
        int maxiH = 0;
        for(int i = 0; i<hBarSize; i++){
            if(hBars[i] == prev+1){
                consH++;
            }else{
                maxiH = max(maxiH, consH);
                consH = 1;
            }
            prev = hBars[i];
        }
        maxiH = max(maxiH, consH);

        prev = 1;
        int consV = 0;
        int maxiV = 0;
        for(int i = 0; i<vBarSize; i++){
            if(vBars[i] == prev+1){
                consV++;
            }else{
                maxiV = max(maxiV, consV);
                consV = 1;
            }
            prev = vBars[i];
        }
        maxiV = max(maxiV, consV);

        int side = min(maxiV+1, maxiH+1);
        return side*side;


    }
};
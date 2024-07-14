class Solution {
public:
    int minimumCost(int m, int n, vector<int>& horizontalCut,
                    vector<int>& verticalCut) {
        sort(horizontalCut.begin(), horizontalCut.end(), greater<int>());
        sort(verticalCut.begin(), verticalCut.end(), greater<int>());
        int index1 = 0;
        int index2 = 0;
        int verticals = 1;
        int horizontals = 1;
        int ans = 0;
        while(index1 < m-1 && index2 < n-1){
            if(horizontalCut[index1] > verticalCut[index2]){
                ans+= (horizontalCut[index1])*(horizontals);
                verticals++;
                index1++;
            }else{
                ans+= (verticalCut[index2])*(verticals);
                horizontals++;
                index2++;
            }
        }

        while(index1 < m-1){
            ans+= (horizontalCut[index1])*(horizontals);
            index1++;
        }

        while(index2 < n-1){
            ans+= (verticalCut[index2])*(verticals);
            index2++;
        }

        return ans;
    }
};
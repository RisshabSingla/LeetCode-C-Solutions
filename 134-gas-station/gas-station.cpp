class Solution {
public:
    // bool checkPossible(vector<int>& gas, vector<int>& cost, int index, int n) {
    //     int currGas = 0;
    //     int curr = index;
    //     for (int i = 0; i < n - 1; i++) {
    //         currGas = currGas + gas[curr];
    //         if (currGas <= cost[curr]) {
    //             return false;
    //         }
    //         currGas -= cost[curr];
    //         curr = (curr + 1) % n;
    //     }
    //     return true;
    // }

    int findAns(vector<int>& gas, vector<int>& cost) {
        int total = 0;
        int sum = 0;
        int pos = 0;
        for (int i = 0; i < gas.size(); i++) {
            sum += (gas[i] - cost[i]);
            if (sum < 0) {
                total += sum;
                sum = 0;
                pos = i + 1;
            }
        }
        total += sum;
        return total >= 0 ? pos : -1;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        return findAns(gas, cost);

        // int minCost = INT_MAX;
        // int index = -1;
        // int n = cost.size();
        // double ratio = 0;
        // for(int i = 0; i<n; i++){
        //     double r = gas[i] / (double)cost[i];
        //     if(r > ratio){
        //         ratio = r;
        //         index = i;
        //     }
        // }

        // cout<<"index is: "<<index<<"\n";
        // if(checkPossible(gas, cost, index, n)){
        //     return index;
        // }
        // return -1;
    }
};
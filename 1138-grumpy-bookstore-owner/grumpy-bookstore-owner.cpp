class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int satisfied = 0;
        int curr = 0;
        for(int i = 0; i<minutes; i++){
            if(grumpy[i]){
                curr+= customers[i];
            }else{
                satisfied += customers[i];
            }
        }
        int maxiUnsatisfied =  curr;
        for(int i = minutes; i<customers.size(); i++){
            if(grumpy[i-minutes]){
                curr-=customers[i-minutes];
            }
            if(grumpy[i]){
                curr+=customers[i];
            }else{
                satisfied += customers[i];
            }
            maxiUnsatisfied = max(maxiUnsatisfied, curr);
        }
        return satisfied+maxiUnsatisfied;
    }
};
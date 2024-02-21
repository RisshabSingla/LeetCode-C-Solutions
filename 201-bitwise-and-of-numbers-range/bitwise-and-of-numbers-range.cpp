class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        if(left == 0 || right == 0){
            return 0;
        }
        if(left == right){
            return left;
        }
        int val = pow(2, (int)(log2(right)));
        int curr = left;
        // cout<<"val is: "<<val<<"\n";
        for(long long i = max(val, left); i<=right; i++){
            curr = curr & i;
            // cout<<"Curr is: "<<curr<<"\n";
            if(curr == 0){
                break;
            }
        }
        return curr;
    }
};
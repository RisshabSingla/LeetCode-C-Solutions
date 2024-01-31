class Solution {
public:
    bool isValid(vector<int>&ans, int n){

        // for(int i = 0; i<n-1; i++){
        //     if(__builtin_popcount(ans[i] xor ans[i+1]) != 1){
        //         return false;
        //     }
        // }
        if(__builtin_popcount(ans[0] xor ans[n-1]) == 1){
            return true;
        }
        return false;
    }
    // bool recursive(vector<int>&ans, int index, int n,
    // unordered_map<int,int>&done){
    //     if(index == n){
    //         if(isValid(ans,n)){
    //             return true;
    //         }
    //         return false;
    //     }
    //     for(int i = 0; i<n; i++){
    //         if(done[i] == 0){
    //             // cout<<"Placing "<<i<<" at: "<<index<<"\n";
    //             ans[index] = i;
    //             done[i]++;
    //             if(recursive(ans,index+1, n, done)){
    //                 return true;
    //             }
    //             done[i]--;
    //         }
    //     }
    //     return false;
    // }

    bool recursive2(vector<int>& ans, int index, int n,
                    unordered_map<int, int>& done, int prev, int bits) {
        if (index == n) {
            if (isValid(ans, n)) {
                return true;
            }
            return false;
        }
        for (int i = 0; i <bits; i++) {
            int a = prev xor (1 << i);
            // cout<<"a is: "<<a<<"\n";
            if (done[a] == 0) {
                done[a]++;
                ans[index] = a;
                if (recursive2(ans, index + 1, n, done, ans[index], bits)) {
                    return true;
                }
                done[a]--;
            }
        }
        return false;
    }
    vector<int> circularPermutation(int n, int start) {
        vector<int> ans(pow(2, n), 0);
        ans[0] = start;
        unordered_map<int, int> done;
        done[start]++;
        recursive2(ans, 1, pow(2, n), done, start, n);
        return ans;

        // recursive(ans, 1, pow(2,n), done);
        // for(auto i: ans){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // return ans;
    }
};
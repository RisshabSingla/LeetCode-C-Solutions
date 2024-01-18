class Solution {
public:
    // int helper(int n, int*arr){
    //     if(n == 1){
    //         arr[1] = 1;
    //         arr[0] = 1;
    //         return 1;
    //     }

    //     if(arr[n-1] == -1){
    //         arr[n-1] = helper(n-1, arr);
    //     }
    //     if(arr[n-2] == -1){
    //         arr[n-2] = helper(n-2, arr);
    //     }

    //     return (arr[n-1] + arr[n-2]);
    // }

    int climbStairs(int n) {
        int arr[50] ={0};
        arr[0] = 1;
        arr[1] = 1;
        for(int i = 2; i<=n; i++){
            arr[i] = arr[i-1]+arr[i-2];
        }
        return arr[n];
        // return helper(n, arr);
    }
};
class Solution {
public:
    int findWays(vector<int>& arr, int mid, int n) {
        int smallerL = 0;
        int largerL = 0;
        int smallerR = 0;
        int largerR = 0;
        for (int i = 0; i < mid; i++) {
            if (arr[i] < arr[mid]) {
                smallerL++;
            }
            if (arr[i] > arr[mid]) {
                largerL++;
            }
        }
        for (int i = mid + 1; i < n; i++) {
            if (arr[i] < arr[mid]) {
                smallerR++;
            }
            if (arr[i] > arr[mid]) {
                largerR++;
            }
        }
        return ((smallerL * largerR) + (largerL * smallerR));
    }
    int numTeams(vector<int>& arr) {
        // int n = arr.size();
        // int count = 0;
        // for(int i = 0; i<n; i++){
        //     for(int j = i+1; j<n;j++){
        //         for(int k = j+1; k<n; k++){
        //             if(arr[i] > arr[j] && arr[j] > arr[k]){
        //                 count++;
        //             }
        //             if(arr[i] < arr[j] && arr[j] < arr[k]){
        //                 count++;
        //             }
        //         }
        //     }
        // }
        // return count;

        int n = arr.size();
        int count = 0;
        for (int j = 1; j < n - 1; j++) {
            count += findWays(arr, j, n);
        }
        return count;
    }
};
class Solution {
public:
    int pivotInteger(int n) {
        int low = 1;
        int high = n;
        int sumN = ((n)*(n+1))/2;
        while(low<=high){
            int mid = low+(high-low)/2;
            int sum1 = ((mid)*(mid+1))/2;
            int sum2 = sumN-sum1+mid;
            if(sum1 == sum2){
                return mid;
            }
            if(sum1>sum2){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return -1;
    }
};
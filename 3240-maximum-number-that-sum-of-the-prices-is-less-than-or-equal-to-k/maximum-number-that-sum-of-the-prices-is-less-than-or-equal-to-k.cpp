class Solution {
public:
    long long bitSum[64];
    long long findCost(long long num, int x){
        long long count = 0;
        long long mul = 1;
        while(mul*x <= 64){
            long long shift = (mul*x)-1;
            count+= (num>>shift) & 1;
            mul++;
        }
        return count;
    }

    void populateBitSum(long long number){
        if(number == 0){
            return;
        }
        if(number == 1){
            bitSum[0]++;
            return;
        }
        if(number == 2){
            bitSum[0]++;
            bitSum[1]++;
            return;
        }
        // cout<<"Number is: "<<number<<"\n";
        long long MSB = log2(number);
        long long count = (1LL<<MSB);
        bitSum[MSB]+= (number - count+1);

        for(int i = 0; i<MSB; i++){
            bitSum[i]+= (count)/2;
        }
        populateBitSum(number-count);
    }



    long long findMaximumNumber(long long k, int x) {
        // Approach 1: Brute Force
        // long long total_cost = 0;
        // long long num = 1;
        // while(total_cost <= k){
        //     long long cost = findCost(num , x);
        //     total_cost+= cost;
        //     // cout<<"Num is: "<<num<<" Cost is: "<<cost<<" total: "<<total_cost<<"\n";
        //     num++;
        // }
        // if(total_cost == k){
        //     return num-1;
        // }
        // return num-2;


        // Approach 2: Bit Manipulation

        long long start = 1;
        long long end = 1e15;
        long long ans = 0;
        while(start <= end){
            long long mid = start + (end-start)/2;
            memset(bitSum, 0, sizeof(bitSum));
            populateBitSum(mid);
            long long res = 0;
            for(int i = 0; i<63; i++){
                if((i+1)%x == 0){
                    res+= bitSum[i];
                }
            }
            if(res <= k){
                ans = mid;
                start = mid+1;
            } else{
                end = mid-1;
            }
        }
        return ans;
    }
};
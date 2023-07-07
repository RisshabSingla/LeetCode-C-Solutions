class Solution {
public:
    int findPrimes(long long n){
        int count = 0;
        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;
        for(long long i=2;i<n;i++){
            if(sieve[i]==false){
                continue;
            }
            count++;
            for(long long j=i*i;j<n;j+=i){
                sieve[j]=false;
            }
        }
        return count;
    }
    int countPrimes(int n) {
        if(n == 0 || n == 1){
            return 0;
        }
        return findPrimes(n);
        // vector<int> primes;
        // findPrimes(n, primes);
        // return primes.size();
    }
};
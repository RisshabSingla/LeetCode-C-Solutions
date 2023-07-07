class Solution {
public:
    void findPrimes(long long n, vector<int> &primes){
        // vector<int> primes;
        vector<bool> sieve(n, true);
        sieve[0] = false;
        sieve[1] = false;
        for(long long i=2;i<n;i++){
            if(sieve[i]==false){
                continue;
            }
            primes.push_back(i);
            for(long long j=i*i;j<n;j+=i){
                sieve[j]=false;
            }
        }
    }
    int countPrimes(int n) {
        if(n == 0 || n == 1){
            return 0;
        }
        vector<int> primes;
        findPrimes(n, primes);
        return primes.size();
    }
};
class Solution {
public:
    vector<int> findPrimes(long long n){
        vector<int> primes;
        vector<bool> sieve(n+1, true);
        sieve[0] = false;
        sieve[1] = false;
        for(long long i=2;i<=n;i++){
            if(sieve[i]==false){
                continue;
            }
            primes.push_back(i);
            for(long long j=i*i;j<n;j+=i){
                sieve[j]=false;
            }
        }
        return primes;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<int> primes = findPrimes(n);
        // for(auto i : primes){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int front = 0 ;
        int last = primes.size()-1;
        vector<vector<int>> ans;
        while(front<=last){
            int sum = primes[front]+ primes[last];
            if(sum == n){
                vector<int> p;
                p.push_back(primes[front]);
                p.push_back(primes[last]);
                ans.push_back(p);
            }
            if(sum < n){
                front++;
            }else{
                last--;
            }
        }
        return ans;
    }
};
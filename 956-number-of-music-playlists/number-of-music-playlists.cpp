class Solution {
public:
    int mod = 1e9 + 7;
    int dp[101][101];

    int helperMemo(long long songs, long long length, long long k, long long n){
        if(length == 0 && songs == 0){
            return 1;
        }

        if(length == 0|| songs == 0){
            return 0;
        }

        if(dp[songs][length] != -1){
            return dp[songs][length];
        }

        // adding a new song in the sequence  
        // total possible for (length-1, songs-1)*(remaining unused songs)   
        long long a = (helperMemo(songs-1, length-1, k,n)*(n-songs+1))%mod;
        
        // adding a already existing songs in the sequence
        // total possible for (songs, length-1)*(using the number of songs before k songs)
        long long b = 0;
        if(songs-k > 0){
            b = ((songs-k)*helperMemo(songs, length-1,k,n))%mod;
        }
        dp[songs][length] =  (a + b)%mod;
        return dp[songs][length];
    }

    int helper(long long songs, long long length, long long k, long long n){
        if(length == 0 && songs == 0){
            return 1;
        }

        if(length == 0 && songs > 0){
            return 0;
        }

        if(length > 0 && songs == 0){
            return 0;
        }

        if(length<0 || songs < 0){
            return 0;
        }

        // adding a new song in the sequence  
        // total possible for (length-1, songs-1)*(remaining unused songs)   
        long long a = helper(songs-1, length-1, k,n)*(n-songs+1);
        
        // adding a already existing songs in the sequence
        // total possible for (songs, length-1)*(using the number of songs before k songs)
        long long b = (songs-k)*helper(songs, length-1,k,n);
        b = max(b,0LL);
        return (a + b)%mod;
    }

    int numMusicPlaylists(int n, int goal, int k) {
        
        if(n == goal){
            // simple n!
            long long ans = 1;
            for(int i = 1; i<=n; i++){
                ans = ans*i;
                ans = ans%mod;
            }
            return (int)ans;
        }

        // return helper(n, goal, k,n);
        
        for(int i = 0; i<101; i++){
            for(int j = 0; j<101; j++){
                dp[i][j] = -1;
            }
        }

        return helperMemo(n, goal, k,n);


        return 0;
    }
};
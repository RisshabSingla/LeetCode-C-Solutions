class Solution {
public:
    bool isPrime[1000000];
    void generateNumbers(vector<vector<int>>& mat, int startX, int startY, int xMove, int yMove,int currentNumber, unordered_map<int,int>& freq, int n, int m){
        currentNumber = currentNumber*10 + mat[startX][startY];
        if(currentNumber > 10 && isPrime[currentNumber]){
            freq[currentNumber]++;
        }
        // cout<<"Current Number is: "<<currentNumber<<"\n";
        if(startX+xMove < n && startX+xMove>=0 && startY+yMove < m && startY+yMove >=0){
            generateNumbers(mat, startX+xMove, startY+yMove, xMove, yMove, currentNumber, freq, n,m);
        }
    }
    int mostFrequentPrime(vector<vector<int>>& mat) {
        memset(isPrime, true, sizeof(isPrime));
        for (int p = 2; p * p < 1000000; p++) {
            if (isPrime[p] == true) {
                for (int i = p * p; i < 1000000; i += p)
                    isPrime[i] = false;
            }
        }
        
        int dir_x[] = {1, 0, -1};
        int dir_y[] = {1, 0, -1};
        unordered_map<int,int> freq;
        int n = mat.size();
        int m = mat[0].size();
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                for(int i = 0;i<3; i++){
                    for(int j = 0; j<3; j++){
                        if(i == 1 && j == 1){
                            continue;
                        }
                        if(x+dir_x[i] < n && x+dir_x[i]>=0 && y+dir_y[j] < m && y+dir_y[j] >=0){
                            generateNumbers(mat,x+dir_x[i], y+dir_y[j], dir_x[i], dir_y[j], mat[x][y], freq, n,m);
                        }
                    }
                }
            }
        }
        int maxi = 0;
        int count = 0;
        for(auto &i : freq){
            // cout<<i.first<<" "<<i.second<<"\n";
            if(i.second >= count && i.first > 10){
                if(i.second == count){
                    maxi = max(maxi, i.first);
                }else{
                    maxi = i.first;
                }
                count = i.second;
            }
        }
        if(maxi == 0){
            return -1;
        }
        return maxi;
        
    }
};
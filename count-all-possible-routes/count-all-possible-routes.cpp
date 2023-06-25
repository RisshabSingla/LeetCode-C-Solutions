class Solution {
public:
    void helperDP(vector<int>& locations, int start, int finish, int fuel, int size, vector<vector<int>> &dp){

    }


        int helperMem(vector<int>& locations, int start, int finish, int fuel, int size,vector<vector<int>> &dp){
        int count = 0;
        if(start == finish && fuel >=0){
            // cout<<"Reached Destination"<<endl;
            count++;
            count = count % 1000000007;
        }
        
        if(fuel <0 ){
            return 0;
        }

        if(dp[start][fuel] != -1){
            return dp[start][fuel];
        }
        
        for(int i = 0;i<size; i++){
            if(i == start){
                continue;
            }
            int diff = abs(locations[start] - locations[i]);
            // cout<<"Going from: "<<start<<" to: "<<i<<" with fuel: "<<fuel - diff<<endl;
            count+= helperMem(locations, i, finish, fuel - diff,size,dp);
            count = count % 1000000007;
        }
        dp[start][fuel] = count;
        return count;
    }

    void helperRec(vector<int>& locations, int start, int finish, int fuel, int &count, int size){
        if(start == finish && fuel >=0){
            // cout<<"Reached Destination"<<endl;
            count++;
            count = count % 1000000007;
        }
        
        if(fuel <=0 ){
            return;
        }
        
        for(int i = 0;i<size; i++){
            if(i == start){
                continue;
            }
            int diff = abs(locations[start] - locations[i]);
            // cout<<"Going from: "<<start<<" to: "<<i<<" with fuel: "<<fuel - diff<<endl;
            helperRec(locations, i, finish, fuel - diff, count,size);
        }
    }
    
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        // int count = 0;
        // int size = locations.size();
        // helperRec(locations, start, finish, fuel, count,size);
        // return count;

        int size = locations.size();
        vector<vector<int>> dp(size, vector<int>(fuel+1, -1));
        return helperMem(locations, start, finish, fuel,size,dp);

    }
};
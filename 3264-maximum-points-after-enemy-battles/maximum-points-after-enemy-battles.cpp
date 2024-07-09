class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) {
        long long points = 0;
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(enemyEnergies[0] > currentEnergy){
            return 0;
        }
        long long sum = 0;
        for(auto i: enemyEnergies){
            sum+= (long long)i;
        }
        sum-=enemyEnergies[0];
        long long current = sum + currentEnergy;
        // cout<<"Current is: "<<current<<"\n";
        // while(current >= enemyEnergies[0]){
        //     points++;
        //     current-=enemyEnergies[0];
        // }
        return current/enemyEnergies[0];
    }
};
class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        vector<vector<long long>> people = {{delay+1, forget+1,1}};
        long long time =1;
        long long mod = 1e9+7;
        while(time<= n){
            
            while(!people.empty() && people[0][1] == time){
                people.erase(people.begin());
            }
            long long count = 0;
            for(auto &i: people){
                if(i[0] <= time){
                    count+= i[2];
                }
                count%= mod;
            }
            people.push_back({time+delay, time+forget, count});
            time++;
        }
        long long count = 0;
        for(auto &i: people){
            count+= i[2];
            count%= mod;
        }
        return count;
        
    }
};
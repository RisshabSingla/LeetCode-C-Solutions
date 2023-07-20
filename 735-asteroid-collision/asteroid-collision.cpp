class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> ans;
        int size = asteroids.size();
        ans.push_back(asteroids[0]);
        int ans_size = 1;
        for(int i = 1; i<size; i++){
            ans_size = ans.size();
            if(ans_size == 0){
                ans.push_back(asteroids[i]);
            }
            else{
                int ast = asteroids[i];
                bool destroyed = false;
                for(int j = ans_size-1; j>=0; j--){
                    if((ast < 0 && ans[j] > 0)){
                        // collision condition
                        if(abs(ast) < abs(ans[j])){
                            destroyed = true;
                            break;
                        }
                        else if(abs(ast) == abs(ans[j])){
                            destroyed = true;
                            ans.erase(ans.begin() + j);
                            break;
                        }else{
                            // asteroid in answer destroyed
                            ans.erase(ans.begin() + j);
                        }
                    }
                }
                if(!destroyed){
                    ans.push_back(asteroids[i]);
                } 
            }
        }
        return ans;
    }
};
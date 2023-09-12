class AuthenticationManager {
public:
    map<string,int> tokens;
    int ttl;
    AuthenticationManager(int timeToLive) {
        ttl = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        tokens[tokenId] = currentTime + ttl;
    }
    
    void renew(string tokenId, int currentTime) {
        if(tokens.count(tokenId)==0){
            return;
        }
        int exp = tokens[tokenId];
        if(exp > currentTime){
            tokens[tokenId] = currentTime + ttl;
        }
    }
    
    int countUnexpiredTokens(int currentTime) {
        int count = 0;
        for(auto itr: tokens){
            if(itr.second > currentTime){
                count++;
            }
        }
        return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
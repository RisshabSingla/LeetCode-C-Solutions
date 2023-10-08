class Compare{
    public:

    bool operator()(pair<int,string>& p1,pair<int,string>&p2){
        if(p1.first == p2.first){
            return p1.second>p2.second;
        }
        return p1.first<p2.first;
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> mp;
        for(int i = 0; i<words.size(); i++){
            mp[words[i]]++;
        }
        priority_queue<pair<int,string>, 
                vector<pair<int,string>>, 
                Compare> pq; 
        for(auto i: mp){
            pq.push({i.second, i.first});
        }
        vector<string> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;


    }
};
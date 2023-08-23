class Solution {
public:
    string reorganizeString(string s) 
    {
        int length = s.length(); 
        vector<int> freq(26,0);
        for(int i = 0; i<length; i++){
            freq[s[i]-'a']++;
            if(freq[s[i]-'a'] > ((length+1)/2)){
                return "";
            }
        }

        priority_queue<pair<int,char>>pq; 
        for(int i = 0; i<26; i++){
            if(freq[i]>0){
                pq.push({freq[i], 'a'+i});
            }
        }  

        string ans = "";
        while(pq.size()>1)
        {
            pair<int,char> top1 = pq.top();
            pq.pop();
            pair<int,char> top2 = pq.top();
            pq.pop();

            ans.push_back(top1.second);
            ans.push_back(top2.second);

            top1.first--;
            top2.first--;

            if(top1.first>0)
              pq.push(top1);

            if(top2.first>0)
              pq.push(top2);  
        }

        // O(n * log(n)) // for each occurence once
        if(!pq.empty())
        {
            ans.push_back(pq.top().second);
            pq.pop();
        }
    
      return ans;
    }
};
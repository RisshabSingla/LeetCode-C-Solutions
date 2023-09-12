class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0);
        int slen = s.length();
        for(int i = 0; i<slen; i++){
            freq[s[i]-'a']++;
        }
        unordered_set<int> present;
        int deletions = 0;
        for(int i = 0; i<26; i++){
            if(freq[i] == 0){
                continue;
            }
            cout<<"Char is: "<<char('a'+i);
            auto itr = present.find(freq[i]);
            if(itr != present.end()){
                cout<<" already: "<<freq[i];
                // present.erase(itr);
                int back = 1;
                while(present.find(freq[i]-back) != present.end()){
                    back++;
                }
                if(freq[i]-back>0){
                    cout<<" new: "<<(freq[i]-back)<<endl;
                    deletions+=back;
                    present.insert(freq[i]-back);
                }else{
                    deletions+=freq[i];
                    cout<<" new: 0"<<endl;
                }
            }else{
                cout<<" Inserting first: "<<freq[i]<<endl;
                present.insert(freq[i]);
            }


            cout<<"present is: ";
            for(auto i: present){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        return deletions;
    }
};
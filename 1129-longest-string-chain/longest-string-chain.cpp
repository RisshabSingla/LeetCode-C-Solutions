class Solution {
public:
    static bool comp(string &a, string &b){
        return a.length() < b.length();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mapping;
        int wlen = words.size();
        // for(int i = 0; i<wlen; i++){
        //     mapping[words[i]] = 1;
        // }
        sort(words.begin(), words.end(), comp);
        // for(auto i: words){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int longest_chain = 0;
        for(int i = 0; i<wlen; i++){
            // cout<<"Word is: "<<words[i]<<" : ";
            int count = 1;
            for(int j = 0; j<words[i].length();j++){
                string new_word = words[i].substr(0, j) + words[i].substr(j+1);
                if(mapping.count(new_word)){
                    count = max(count, mapping[new_word]+1);
                }
                // cout<<new_word<<" : ";
            }
            mapping[words[i]] = count;
            longest_chain = max(longest_chain, mapping[words[i]]);
            // cout<<endl;
        }

        // for(auto i: mapping){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }
        return longest_chain;

    }
};
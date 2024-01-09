class Solution {
public:
    static bool comp(vector<string> &a, vector<string>&b ){
        if(a[0] != b[0]){
            return a[0] < b[0];
        }
        return a[1] < b[1];
    }

    int findDiff(string &str1, string &str2){
        return (stoi(str2)- stoi(str1));
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& arr) {
        // sort(arr.begin(), arr.end(), comp);
        unordered_map<string, vector<string>> timing;
        for(auto &i: arr){
            timing[i[0]].push_back(i[1]);
        }
        vector<string> ans;
        for(auto  &i: timing){
            if(i.second.size() < 3){
                continue;
            }
            sort(i.second.begin(), i.second.end());
            // cout<<i.first<<" ";
            for(int j = 0; j<i.second.size()-2; j++){
                int diff = findDiff(i.second[j], i.second[j+2]);
                // cout<<diff<<"\n";
                if(diff< 100){
                    ans.push_back(i.first);
                    break;
                }
            }
            // for(auto &j: i.second){
            //     cout<<j<<" ";
            // }
            // cout<<"\n";
        }
        return ans;
    }
};
class Solution {
public:

    bool dfs(unordered_map<string, vector<string>> &mapping, vector<string> &ans, string curr, int count , int tickets){
        if(curr == "###"){
            return false;
        }

        if(count == tickets){
            return true;
        }

        for(int i = 0; i<mapping[curr].size(); i++){
            ans.push_back(mapping[curr][i]);
            string nxt = mapping[curr][i];
            mapping[curr][i] = "###";
            bool a = dfs(mapping, ans, nxt, count+1, tickets);
            if(a){
                return true;
            }
            // backtrack;
            mapping[curr][i] = nxt;
            ans.pop_back();
        }
        return false;
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string> ans;
        unordered_map<string, vector<string>> mapping;
        sort(tickets.begin(), tickets.end());
        for(int i = 0; i<tickets.size(); i++){
            mapping[tickets[i][0]].push_back(tickets[i][1]);
        }

        // map<string, vector<string> >::iterator it;
        // for(it = mapping.begin(); it != mapping.end(); it++){
        //     sort(it->second.begin(), it->second.end());
        // }

        // for(auto i : mapping){
        //     cout<<i.first<<" :";
        //     sort(i.second.begin(), i.second.end());
        //     for(auto j : i.second){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        // }

        int count = 0;
        int no_tickets = tickets.size();
        string curr = "JFK";
        ans.push_back(curr);

        dfs(mapping, ans, "JFK",0, no_tickets);
        return ans;

        // return ans;



        // while(count != no_tickets){
        //     vector<string> possible = mapping[curr];
        //     cout<<"Curr is: "<<curr<<endl;
        //     for(auto j: possible){
        //         cout<<j<<" ";
        //     }
        //     cout<<endl;
        //     cout<<"Size is: "<<possible.size()<<endl;
        //     for(int i = 0; i<mapping[curr].size(); i++){
        //         cout<<"Dest: "<<possible[i]<<endl;
        //         if(mapping[curr][i]!= "###"){
        //             string nxt = mapping[curr][i];
        //             if(mapping.count(nxt) == 0 && count != no_tickets-1){
        //                 continue;
        //             }
        //             mapping[curr][i] = "###";
        //             curr = nxt;
        //             ans.push_back(curr);
        //             count++;
        //             break;
        //         }
        //     }
        // }
        return ans;

    }
};
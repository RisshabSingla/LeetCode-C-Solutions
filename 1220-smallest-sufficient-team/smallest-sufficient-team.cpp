class Solution {
public:
    void helper(bitset<16> skill_set ,  vector<bitset<16>> &people, vector<int> &ans, int skills, vector<int>& t_ans, int curr_index, int size){
        if(ans.size() > 0 && t_ans.size() > ans.size()){
            return;
        }
        if(skill_set.count() == skills ){
                // cout<<"Set bits are: "<<skill_set.count()<<endl;
                // cout<<"t_ans is: ";
                // for(auto i : t_ans){
                //     cout<<i<<" ";
                // }
                // cout<<endl;

                if(t_ans.size() < ans.size() || ans.size() == 0){
                    ans = t_ans;   
                }
                return;
        }

        if(curr_index == size){
            return;
        }

        bitset p = people[curr_index];
        if(p.count() > 0){
            bitset<16> n(skill_set);
            n = n | p;
            // cout<<"Bitset after including is: "<<n.to_string()<<endl;
            t_ans.push_back(curr_index);
            // including the current person
            helper(n , people, ans, skills, t_ans, curr_index+1,size);
            t_ans.pop_back();
        }

        // not including the current person
        helper(skill_set , people, ans, skills, t_ans, curr_index+1,size);

    }


    int solve(vector<int>&skill_person,int curr_mask, int curr_index, vector<vector<int>> &dp, vector<vector<int>> &choice, int &no_people, int &req_mask){
        if(curr_mask == req_mask){
            return 0;
        }
        if(curr_index == no_people){
            return 10000;
        }
        if(dp[curr_mask][curr_index] != -1){
            return dp[curr_mask][curr_index];
        }


        int including = solve(skill_person, curr_mask|skill_person[curr_index], curr_index+1, dp,choice, no_people, req_mask) + 1;
        int not_including = solve(skill_person, curr_mask, curr_index+1, dp,choice, no_people, req_mask);


        if(including< not_including){
            choice[curr_mask][curr_index] = 1;
        }
        dp[curr_mask][curr_index] = min(including, not_including);
        return dp[curr_mask][curr_index];
    }




    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) {
        // int skills = req_skills.size();
        // int size = people.size();
        // bitset<16> skill_set;
        // unordered_map<string, int> mapping;
        // for(int i = 0; i<skills; i++){
        //     mapping[req_skills[i]] = i;
        // }   

        // vector<bitset<16>> people_skills;
        // for(auto i: p){
        //     bitset<16> b;
        //     for(auto j : i){
        //         int a = mapping[j];
        //         b.set(a);
        //     }
        //     // cout<<"Bitset is: "<<b.to_string()<<endl;
        //     people_skills.push_back(b);
        // }

        // // recursive approach
        // vector<int> ans;
        // vector<int> t_ans;
        // helper(skill_set, people, ans, skills,t_ans,0, size);
        // return ans;



        // Memoization:

        // int skills = req_skills.size();
        // int no_people = people.size();
        // int possible = pow(2, skills);
        
        // unordered_map<string, int> mapping;
        // for(int i = 0; i<skills; i++){
        //     mapping[req_skills[i]] = i;
        // }

        // vector<int> skill_person(no_people);
        // for(int i = 0; i<no_people; i++){
        //     int size = people[i].size();
        //     int val = 0;
        //     for(int j = 0; j<size; j++){
        //         int index = mapping[people[i][j]];
        //         val = val | (1<<index);
        //     }
        //     skill_person[i] = val;
        // }


        // int req_mask = (1<<skills)-1;
        // vector<vector<int>> dp(possible,vector<int>(no_people+1 ,-1));
        // vector<vector<int>> choice(possible,vector<int>(no_people+1 ,-1));

        // solve(skill_person,0, 0, dp, choice, no_people, req_mask);

        // vector<int> ans;
        // int mask = 0;
        // for(int i = 0; i<no_people; i++){
        //     if(choice[mask][i] == 1){
        //         ans.push_back(i);
        //         mask = mask| skill_person[i];
        //     }
        //     if(mask == req_mask){
        //         break;
        //     }
        // }

        // return ans;


        // Dynamic Programming Approach

        int skills = req_skills.size();
        int no_people = people.size();
        int possible = pow(2, skills);
        
        unordered_map<string, int> mapping;
        for(int i = 0; i<skills; i++){
            mapping[req_skills[i]] = i;
        }


        unordered_map<int, vector<int>> dp;
        dp.reserve(1 << skills);
        dp[0] = {};

        for(int i = 0; i<no_people; i++){
            int size = people[i].size();
            int val = 0;
            for(int j = 0; j<size; j++){
                int index = mapping[people[i][j]];
                val = val | (1<<index);
            }


            for (auto it: dp) {
                int comb = it.first | val;
                if (dp.find(comb) == dp.end() || 
                    dp[comb].size() > 1 + dp[it.first].size()){
                        dp[comb] = it.second;
                        dp[comb].push_back(i);
                }
            }
        }

        return dp[possible-1];


        
    }
};
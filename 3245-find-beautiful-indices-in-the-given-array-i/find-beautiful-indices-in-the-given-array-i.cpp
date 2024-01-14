class Solution {
public:
    vector<int> beautifulIndices(string str, string a, string b, int k) {
       
        vector<long long> aPresentIndex;
        vector<long long> bPresentIndex;
        
        long long foundA = str.find(a);
        while(foundA != string::npos){
             aPresentIndex.push_back(foundA);
             foundA = str.find(a, foundA+1);
        }
        
        long long foundB = str.find(b);
        while(foundB != string::npos){
              bPresentIndex.push_back(foundB);
             foundB = str.find(b, foundB+1);
        }
        
        // for(auto i: aPresentIndex){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        // for(auto i: bPresentIndex){
        //     cout<<i<<" ";
        // }
        // cout<<"\n";
        vector<int> ans;
        for(int i = 0; i<aPresentIndex.size(); i++){
            int lower = aPresentIndex[i] - k;
            int index = lower_bound(bPresentIndex.begin(), bPresentIndex.end(), lower) - bPresentIndex.begin();
            if(index < bPresentIndex.size() && abs(bPresentIndex[index] - aPresentIndex[i]) <= k){
                ans.push_back(aPresentIndex[i]);
            }
            // cout<<bPresentIndex[index]<<"\n";
            // for(int j = 0; j<bPresentIndex.size(); j++){
            //     if(abs(aPresentIndex[i] - bPresentIndex[j]) <= k){
            //         ans.push_back(aPresentIndex[i]);
            //         break;
            //     }
            // }
        }
        return ans;
    }
};
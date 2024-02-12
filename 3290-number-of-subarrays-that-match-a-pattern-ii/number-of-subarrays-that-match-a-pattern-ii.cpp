class Solution {
public:
    // int count = 0;
    void calcLPS(string &p, int LPS[]){
    LPS[0] = 0;
    int i = 0, j = 1;
    while (j < p.length()){
        if (p[i] == p[j]){
            LPS[j] = i + 1;
            i++;
            j++;
        }else{
            if (i == 0){
                LPS[j] = 0;
                j++;
            }
            else{
                i = LPS[i - 1];
            }
        }
    }
}
    int KMP(string &str, string &pattern){
        int slen = str.length();
        int plen = pattern.length();
        int LPS[plen];
        calcLPS(pattern, LPS); // to build the LPS table
        // for(int i = 0; i<plen; i++){
        //     cout<<LPS[i]<<" ";
        // }
        // cout<<"\n";
        int count = 0;
        int i = 0, j = 0;
        while (i < slen)
        {
            if (pattern[j] == str[i])
            {
                // cout<<"Equal\n";
                i++;
                j++;
            } // If there is a match, proceed to check the remaining characters
            if (j == plen)
            {
                // cout <<"Pattern found at index "<< i - plen<<endl; // to print the index of the string where the pattern matches
                count++;
                j = LPS[j - 1];
            }
            else if (i < slen && pattern[j] != str[i])
            {
                // cout<<"Inside else\n";
                if (j == 0)
                    i++;
                else
                    j = LPS[j - 1]; // if there is a mismatch after a few matched characters,
            }                       // proceed to check only from the LPS of the previously
        }
        return count;
    }
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n = nums.size();
        int m = pattern.size();
        string p = "";
        // char p[n];
        // char *p = new char[n-1];
        for(int i = 1; i<n; i++){
            if(nums[i] > nums[i-1]){
                // p[i-1] = 1;
                p+= 'A';
            }else if(nums[i] == nums[i-1]){
                // p[i-1]  = 0;
                p+= 'B';
            }else{
                // p[i-1] = -1;
                p+= 'C';
            }
        }
        
        string text = "";
        // char *text = new char[m];
        for(int i = 0; i<m; i++){
            if(pattern[i] == 0){
                text+=  'B';
            }else if(pattern[i] == 1){
                text+= 'A';
            }else{
                text+= 'C';
            }
        }
        // cout<<p<<"\n";
        // cout<<text<<"\n";
        return KMP(p, text);
        // return count;
    }
};
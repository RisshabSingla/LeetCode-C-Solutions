class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        
        // rotating the string 
        // for(int i = 1; i<s.length(); i++){
        //     bool broken = false;
        //     for(int j = 0; j<s.length(); j++){
        //         int index = i+j;
        //         index = index%(s.length());
        //         char rotate = s[index];
        //         char original = s[j];
        //         // cout<<"Value of i is: "<<i<<endl;
        //         // cout<<"Value of j is: "<<j<<endl;
        //         // cout<<"Value of index is: "<<index<<endl;
        //         // cout<<"Value of rotate is: "<<rotate<<endl;
        //         // cout<<"Value of original is: "<<original<<endl;
        //         if(rotate != original){
        //             broken = true;
        //             break;
        //         }
        //     }
        //     if(!broken){
        //         return true;
        //     }
        // }
        // return false;


        int n=s.size();
        string temp=s+s;
        temp = temp.substr(1,temp.size()-2);
        int ans=temp.find(s);
        if(ans==-1)
        {
            return false;
        }
        return true;


    }
};
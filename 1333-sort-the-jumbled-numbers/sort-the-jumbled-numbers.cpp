class Solution {
public:
    static int findMappedValue(int number, vector<int>& mapping) {
        if(number == 0){
            return mapping[0];
        }
        int digits = log10(number);
        // cout<<"NUmber is: "<<number<<" digits: "<<digits<<"\n";
        int nNumber = 0;
        for (int i = digits; i >= 0; i--) {
            int val = pow(10, i);
            int q = (number / val) % 10;
            // cout<<"q is: "<<q<<"\n";
            int mp = mapping[q];
            nNumber += (mp * val);
            // cout<<"nNumber is: "<<nNumber<<"\n";
        }
        return nNumber;
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        for (auto i : nums) {
            findMappedValue(i, mapping);
        }
        sort(nums.begin(), nums.end(), [&](const int& a, const int& b) -> bool {
            int n1 = findMappedValue(a, mapping);
            int n2 = findMappedValue(b, mapping);
            return n1<n2;
        }) ;
        return {nums};
    }
};
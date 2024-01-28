class Solution {
public:
    long long flowerGame(int n, int m) {
        long long evenN = (n+1)/2;
        long long evenM = (m+1)/2;
        long long oddN = (n)/2;
        long long oddM = (m)/2;
        return evenN*oddM + evenM*oddN;
    }
};
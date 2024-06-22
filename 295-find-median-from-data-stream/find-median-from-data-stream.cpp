class MedianFinder {
public:
    set<pair<int,int>> ls;
    set<pair<int,int>> rs;
    int n;
    MedianFinder() { n = 0; }

    void addNum(int num) {
        n++;
        if (ls.empty()) {
            ls.insert({num, n});
            return;
        }
        if ((*ls.rbegin()).first < num) {
            rs.insert({num, n});
        } else {
            ls.insert({num, n});
        }
    }

    double findMedian() {
        int leftReqSize = (n / 2) + n % 2;
        // cout<<"n is: "<<n<<"\n";
        // cout<<"left size is: "<<leftReqSize<<"\n";
        while (ls.size() < leftReqSize) {
            ls.insert(*rs.begin());
            rs.erase(*rs.begin());
        }
        while (ls.size() > leftReqSize) {
            rs.insert(*ls.rbegin());
            ls.erase(*ls.rbegin());
        }
        // cout<<"Left is: ";
        // for(auto i: ls){
        //     cout<<i.first<<" ";
        // }
        // cout<<"\nRight is: ";
        // for(auto i: rs){
        //     cout<<i.first<<" ";
        // }
        // cout<<"\n";

        if (ls.size() == rs.size()) {
            double a = (*ls.rbegin()).first;
            double b = (*rs.begin()).first;
            // cout<<"Median: "<<(a + b) / 2.0<<"\n";
            return (a + b) / 2.0;
        }
        // cout<<"Median: "<<((*ls.rbegin()).first / 1.0)<<"\n";
        return ((*ls.rbegin()).first / 1.0);
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
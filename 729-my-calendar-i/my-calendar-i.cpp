class MyCalendar {
public:
    set<pair<int,int>> st;
    MyCalendar() {
        st.insert({0,0});
    }
    
    bool book(int start, int end) {
        auto itr = st.upper_bound({end, -1});
        itr--;
        // cout<<itr->first<<" "<<itr->second<<"\n";
        // if()

        if(itr->second <= start){
            st.insert({start, end});
            return true;
        }
        return false;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
class DataStream {
public:
    int val;
    int count = 0;
    int k_req;
    DataStream(int value, int k) {
        val = value;
        k_req = k;
    }
    
    bool consec(int num) {
        if(num == val){
            count++;
        }else{
            count = 0;
        }
        return count>=k_req;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */
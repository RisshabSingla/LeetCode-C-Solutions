class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> st;
        queue<int> sd;
        int n = students.size();
        int prev = n;
        for(int i = 0; i<n; i++){
            st.push(students[i]);
            sd.push(sandwiches[i]);
        }
        st.push(-1);
        int index = 0;
        while(!st.empty()){
            int front = st.front();
            st.pop();
            if(front == -1){
                int size = st.size();
                if(size == prev){
                    break;
                }
                prev = size;
                st.push(-1);
                continue;
            }
            if(front == sandwiches[index]){
                index++;
            }else{
                st.push(front);
            }
        }
        return st.size();
    }
};
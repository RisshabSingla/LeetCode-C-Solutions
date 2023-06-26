class Solution {
public:
    void printQueue(priority_queue <int, vector<int>, greater<int>> g){
        while (!g.empty()) {
            cout <<g.top()<<" ";
            g.pop();
        }
        cout << '\n';
    }


    long long totalCost(vector<int>& costs, int k, int candidates) {
        priority_queue <int, vector<int>, greater<int>> front;
        priority_queue <int, vector<int>, greater<int>> back;
        front.push(INT_MAX);
        back.push(INT_MAX);

        int index1 = 0;
        while(index1<candidates){
            front.push(costs[index1]);
            index1++;
        }
        int index2 = costs.size()-1;
        int count = candidates;

        while(index2>=index1 && count>0){
            back.push(costs[index2]);
            index2--;
            count--;
        }

        cout<<"Front is: ";
        printQueue(front);
        cout<<"Back is: ";
        printQueue(back);
        
        long long ans = 0;

        for(int i = 0; i<k; i++){
            int frontTop = front.top();
            int backTop = back.top();
            if(frontTop <= backTop){
                ans+= frontTop;
                front.pop();
                if(index1<=index2){
                    front.push(costs[index1]);
                    index1++;
                }
            }else{
                ans+= backTop;
                back.pop();
                if(index1<=index2){
                    back.push(costs[index2]);
                    index2--;
                }
            }
        }
        return ans;


    }
};
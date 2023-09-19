class Solution {
public:
    vector<int> calcPrev(vector<int>&height, int cols){
        stack<int> s;
        s.push(-1);
        vector<int> prev(cols);
        for(int i = 0; i< cols; i++){
            while(s.top() != -1 && height[s.top()] >= height[i]){
                s.pop();
            }
            prev[i] = s.top();
            s.push(i);
        }
        return prev;
    }
    
    
    vector<int> calcNext(vector<int>&height,  int cols){
        stack<int> s;
        s.push(-1);
        vector<int> next(cols);
        for(int i = cols-1; i>=0; i--){
            while(s.top() != -1 && height[s.top()] >= height[i]){
                s.pop();
            }
            next[i] = s.top();
            s.push(i);
        }
        return next;
    }
    int largestRectangleArea(vector<int>& heights) {
        // Approach 1: Brute Force 
        // Time Complexity O(n^2)
        // int size = heights.size();
        // int max_area = 0;
        // for(int i = size-1; i>=0 ; i--){
        //     int area = heights[i];
        //     int j = i+1;
        //     for(j = i+1; j<size; j++){
        //         if(heights[j] < heights[i]){
        //             break;
        //         }
        //     }
        //     int new_area = (j-i)*heights[i];
        //     max_area = max(new_area, max_area);
        // }
        // return max_area;

        // Approach 2: Using stack
        
        int maxArea = INT_MIN;
        int cols = heights.size();
        
        vector<int> prev = calcPrev(heights,cols);
        vector<int> next = calcNext(heights,cols);
        for(int i = 0; i<cols; i++){
            if(next[i] == -1){
                next[i] = cols;
            }
            int breadth = next[i] - prev[i]-1;
            int area = heights[i]*breadth;
            // cout<<"Area is: "<<area<<endl;
            maxArea = max(maxArea, area);
        }
        
        return maxArea;
    }
};
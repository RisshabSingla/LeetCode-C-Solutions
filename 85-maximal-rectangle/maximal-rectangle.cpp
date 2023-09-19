class Solution {
public:
    int calcArea(vector<int> heights, int cols){
        stack<int> s;
        int maxArea = INT_MIN;
        for(int i = 0;i<=cols; i++){
            while(!s.empty() && (i == cols || heights[s.top()] >= heights[i])){
                int h = heights[s.top()];
                s.pop();
                int width;
                if(s.empty()){
                    width = i;
                }else{
                    width = i-s.top()-1;
                }
                maxArea = max(maxArea, width*h);
            }
            s.push(i);
        }

        return maxArea;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxArea = INT_MIN;
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> height(m, 0);
        for(int i = 0; i<n; i++){
            
            for(int j = 0; j<m; j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }else{
                    height[j] = 0;
                }
            }
            int area = calcArea(height,m);
            // cout<<"For i: "<<i<<" area: "<<area<<endl;
            maxArea = max(area, maxArea);
            
        }
        return maxArea;
    }
};
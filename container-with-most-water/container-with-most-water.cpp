class Solution {
public:
    int maxArea(vector<int>& height) {
        int front = 0;
        int last = height.size()-1;
        int max_cap = (last-front)*(min(height[front],height[last]));
        while(front<last){
            int area = (last-front)*(min(height[front],height[last]));
            max_cap = max(max_cap , area);
            if(height[front]<height[last]){
                front++;
            }else{
                last--;
            }
        }
        return max_cap;
    }
};
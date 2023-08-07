class Solution {
public:
    int findPivot(vector<vector<int>>& matrix, int target){
        int left = 0;
        int right = matrix.size();
        while(left<right){
            int mid = left + (right-left)/2;
            if(matrix[mid][0] <= target){
                left = mid+1;
            }else{
                right = mid;
            }
        }
        return left;
    }


    bool binary_search(vector<int> matrix, int target){
        int left = 0;
        int right = matrix.size()-1;
        while(left <= right){
            int mid = left + (right-left)/2;
            if(matrix[mid] == target){
                return true;
            }
            if(matrix[mid] < target){
                left = mid+1;
            }else{
                right = mid-1;
            }
        }
        return false;
    }
    
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() == 1){
            return binary_search(matrix[0], target); 
        }

        int pivot = findPivot(matrix, target);
        // cout<<"pivot is: "<<pivot<<endl;
        if(pivot == 0){
            return false;
        }
        
        return binary_search(matrix[pivot-1], target);

        // return true;
    }
};
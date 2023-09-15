class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int index1 = nums1.size()-1;
        int index2 = 0;
        while(index1>=0 && index2<nums2.size()){
            if(nums1[index1] > nums2[index2]){
                swap(nums1[index1], nums2[index2]);
                index1--;
                index2++;
            }else{
                break;
            }
        }
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        // cout<<"Array is: ";
        // for(auto i : nums1){
        //     cout<<i<<" ";
        // }
        // for(auto i : nums2){
        //     cout<<i<<" ";
        // }
        // cout<<endl;
        int total_len = nums1.size()+nums2.size();
        if(total_len%2 == 1){
            // Odd length 

            int mid = total_len/2;
            if(mid<nums1.size()){
                return nums1[mid];
            }else{
                return nums2[mid-nums1.size()];
            }
        }else{
            int m1 = total_len/2 - 1;
            int m2 = total_len/2;
            if(m1 < nums1.size() && m2 < nums1.size()){
                return (nums1[m1]+nums1[m2])/2.00;
            }else if(m1 >= nums1.size() && m2 >= nums1.size()){
                return (nums2[m1-nums1.size()]+nums2[m2-nums1.size()])/2.00;
            }else{
                return (nums1[m1]+nums2[m2-nums1.size()])/2.00;
            }
        }
        return -1;

    }
};
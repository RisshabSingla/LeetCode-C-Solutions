class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Approach 1: Sorting the array inplace and then finding the median
        // int index1 = nums1.size()-1;
        // int index2 = 0;
        // while(index1>=0 && index2<nums2.size()){
        //     if(nums1[index1] > nums2[index2]){
        //         swap(nums1[index1], nums2[index2]);
        //         index1--;
        //         index2++;
        //     }else{
        //         break;
        //     }
        // }
        // sort(nums1.begin(), nums1.end());
        // sort(nums2.begin(), nums2.end());
        // int total_len = nums1.size()+nums2.size();
        // if(total_len%2 == 1){
        //     // Odd length 
        //     int mid = total_len/2;
        //     if(mid<nums1.size()){
        //         return nums1[mid];
        //     }else{
        //         return nums2[mid-nums1.size()];
        //     }
        // }else{
        //     int m1 = total_len/2 - 1;
        //     int m2 = total_len/2;
        //     if(m1 < nums1.size() && m2 < nums1.size()){
        //         return (nums1[m1]+nums1[m2])/2.00;
        //     }else if(m1 >= nums1.size() && m2 >= nums1.size()){
        //         return (nums2[m1-nums1.size()]+nums2[m2-nums1.size()])/2.00;
        //     }else{
        //         return (nums1[m1]+nums2[m2-nums1.size()])/2.00;
        //     }
        // }
        // return -1;



        // Approach 2: Storing the middle 2 elements 

        // int count = 0;
        // int elem1;
        // int elem2;
        // int total_len = nums1.size() + nums2.size();
        // int index1 = 0;
        // int index2 = 0;
        // int index2req = total_len/2;
        // int index1req = index2req-1;

        // while (index1 < nums1.size() && index2 < nums2.size() ) {
        //     if (nums1[index1] < nums2[index2]) {
        //         if (count == index1req) elem1 = nums1[index1];
        //         if (count == index2req) elem2 = nums1[index1];
        //         count++;
        //         index1++;
        //     }
        //     else {
        //         if (count == index1req) elem1 = nums2[index2];
        //         if (count == index2req) elem2 = nums2[index2];
        //         count++;
        //         index2++;
        //     }
        // }
        // while (index1 < nums1.size()) {
        //     if (count == index1req) elem1 = nums1[index1];
        //     if (count == index2req) elem2 = nums1[index1];
        //     count++;
        //     index1++;
        // }
        // while (index2 < nums2.size()) {
        //     if (count == index1req) elem1 = nums2[index2];
        //     if (count == index2req) elem2 = nums2[index2];
        //     count++;
        //     index2++;
        // }

        // //Find the median:
        // if (total_len % 2 == 1) {
        //     return elem2;
        // }

        // return (elem1+elem2)/2.00;



    int n1 = nums1.size(), n2 = nums2.size();
    //if n1 is bigger swap the arrays:
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);

    int n = n1 + n2; //total length
    int left = (n1 + n2 + 1) / 2; //length of left half
    //apply binary search:
    int low = 0, high = n1;
    while (low <= high) {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        //calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1) r1 = nums1[mid1];
        if (mid2 < n2) r2 = nums2[mid2];
        if (mid1 - 1 >= 0) l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0) l2 = nums2[mid2 - 1];

        if (l1 <= r2 && l2 <= r1) {
            if (n % 2 == 1) return max(l1, l2);
            else return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        //eliminate the halves:
        else if (l1 > r2) high = mid1 - 1;
        else low = mid1 + 1;
    }
    return 0; //dummy statement




    }
};
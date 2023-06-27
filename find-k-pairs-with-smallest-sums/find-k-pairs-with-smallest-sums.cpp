class Solution {
public:

    static bool comp(pair<int,int> &a, pair<int,int> &b){
        return a.first+a.second < b.first+b.second;
    }

    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        // vector<vector<int>> ans;
        // int index1 = 0;
        // int index2 = 0;
        // int size1 = nums1.size();
        // int size2 = nums2.size();
        // while(k-- && index1!=size1 && index2!= size2 ){
        //     vector<int> a = {nums1[index1],nums2[index2]};
        //     ans.push_back(a);
        //     if(nums1[index1] > nums2[index2]){
        //         index1++;
        //     }else if(nums1[index1] < nums2[index2]){
        //         index2++;
        //     }else{
        //         if(index1+1 != size1 && index2+1 != size2 
        //             && nums1[index1+1] > nums2[index2+1] ){
        //                 index2++;
        //         }else{
        //             index1++;
        //         }
        //     }
        // }

        // while(k > 0 && index1 < size1-1 && index2 == size2){
        //     index1++;
        //     vector<int> a = {nums1[index1], nums2[index2-1]};
        //     ans.push_back(a);
        //     k--;
        // }

        // while(k > 0 && index2 < size2-1 && index1 == size1){
        //     index2++;
        //     vector<int> a = {nums1[index1-1], nums2[index2]};
        //     ans.push_back(a);
        //     k--;
        // }


        // return ans;

        int size1 = nums1.size();
        int size2 = nums2.size();
        vector<vector<int>> ans;
        priority_queue<pair<int,int>, vector<pair<int,int>>, decltype(&comp) > pq(comp);

        for(int i = 0; i<size1; i++){
            for(int j = 0; j<size2; j++){
                if(pq.size() < k){
                    pq.push({nums1[i], nums2[j]});
                }

                else if(pq.size() == k && (nums1[i]+nums2[j]) < pq.top().first+pq.top().second){
                    pq.pop();
                    pq.push({nums1[i],nums2[j]});
                }
                else if(pq.size() == k && (nums1[i]+nums2[j]) > pq.top().first+pq.top().second){
                    break;
                }
            }
        }

        while(!pq.empty()){
            pair<int,int> p = pq.top();
            ans.push_back({p.first, p.second});
            pq.pop();
        }
        return ans;



    }


    
};
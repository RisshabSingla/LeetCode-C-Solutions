/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head->next){
            return {-1,-1};
        }
        vector<int> indexes;
        ListNode* ptr = head->next;
        int prev = head->val;
        int index = 0;
        while(ptr && ptr->next){
            if(ptr->val > prev && ptr->val > ptr->next->val){
                indexes.push_back(index);
            }
            if(ptr->val < prev && ptr->val < ptr->next->val){
                indexes.push_back(index);
            }
            prev = ptr->val;
            ptr = ptr->next;
            index++;
        }
        if(indexes.size() == 0){
            return {-1,-1};
        }
        int maxi = indexes[indexes.size()-1] - indexes[0];
        int mini = INT_MAX;
        for(int i = 1; i<indexes.size(); i++){
            mini = min(mini, indexes[i]-indexes[i-1]);
        }
        if(maxi == 0){
            return {-1,-1};
        }
        return {mini, maxi};
    }
};
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
    void reorderList(ListNode* head) {
        vector<int> list;
        ListNode* itr = head;
        while(itr!= NULL){
            list.push_back(itr->val);
            itr = itr->next;
        }

        int left = 0;
        int right = list.size()-1;
        itr = head;
        while(left<=right && itr!= NULL){
            itr-> val = list[left];
            itr = itr->next;
            if(itr == NULL){
                break;
            }
            itr->val = list[right];
            left++;
            right--;
            itr = itr->next;
        }

    }
};
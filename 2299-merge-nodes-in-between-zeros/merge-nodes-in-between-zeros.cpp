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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* ptr = head;
        ListNode* prev = ptr;
        ptr = ptr->next;
        int sum = 0;
        while(ptr){
            if(ptr->val == 0){
                prev->val = sum;
                sum= 0;
                if(ptr->next != NULL){
                    prev = prev->next;
                }
            }
            sum+= ptr->val;
            ptr = ptr->next;
        }
        prev->next = NULL;
        return head;
    }
};
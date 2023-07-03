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
    ListNode* oddEvenList(ListNode* head) {
        // base condition
        if(head == NULL || head->next == NULL){
            return head;
        }
        
        if(head->next != NULL && head->next->next == NULL){
            return head;
        }

        int index = 3;
        ListNode* oddHead = head;
        ListNode* oddTail = head;
        
        ListNode* evenHead = head->next;
        ListNode* evenTail = head->next;

        ListNode* itr = head->next->next;

        while(itr != NULL){
            if(index%2 == 0){
                evenTail->next = itr;
                evenTail = evenTail->next;
            }else{
                oddTail->next = itr;
                oddTail = oddTail->next;
            }
            index++;
            itr = itr->next;
            // cout<<"Index is: "<<index<<endl;
        }
        oddTail->next = evenHead;
        evenTail->next = NULL;
        return head;
    }
};
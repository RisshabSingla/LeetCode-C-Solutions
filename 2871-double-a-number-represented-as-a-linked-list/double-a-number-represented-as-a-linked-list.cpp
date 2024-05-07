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
    int doubleList(ListNode* head){
        if(!head){
            return 0;
        }
        int carry = doubleList(head->next);
        head->val = 2*head->val + carry;
        int c = head->val / 10;
        head->val %= 10;
        return c;
    }
    ListNode* doubleIt(ListNode* head) {
        int carry = doubleList(head);
        if(carry != 0){
            ListNode* n = new ListNode(carry);
            n->next = head;
            return n;
        }
        return head;
    }
};
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
    ListNode* reverse(ListNode* l){
        ListNode* prev = NULL;
        ListNode* curr = l;
        ListNode* nxt = NULL;
        while(curr!= NULL){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        return prev;
    }

    int length(ListNode* p){
        int count = 0;
        while(p!= NULL){
            count++;
            p = p->next;
        }
        return count;
    }


    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* r1 = reverse(l1);
        ListNode* r2 = reverse(l2);

        int length1 = length(r1);
        int length2 = length(r2);

        if(length2>length1){
            ListNode* t = r1;
            r1 = r2;
            r2 = t;
        }

        ListNode* p = r1;
        // r1 is the longer linked list
        int carry = 0;
        ListNode* prev = r1;
        while(r1!= NULL && r2!= NULL){
            r1->val = r1->val + r2->val + carry;
            carry = 0;
            if(r1->val >9){
                r1->val -=10;
                carry = 1;
            }
            prev = r1;      
            r1 = r1->next;
            r2 = r2->next;
        }
        while(carry == 1){ 
            if(r1 == NULL){   
                ListNode* p = new ListNode(1);
                prev->next = p;
                carry = 0;
            }else{
                r1->val++;
                carry = 0;
                if(r1->val>9){
                    r1->val-=10;
                    carry = 1;
                }
                prev = r1;
                r1 = r1->next;
            }
        }

        ListNode* ans = reverse(p);
        return ans;

    }
};
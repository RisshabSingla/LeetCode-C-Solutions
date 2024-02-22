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
    void reverse(ListNode* head) {
        if(!head || !head->next){
            return ;
        }
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* nxt = NULL;
        while(curr){
            nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
    }

    ListNode* findKth(ListNode* head, int k){
        k-=1;
        while(head != NULL && k> 0){
            k--;
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1){
            return head;
        }
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp!= NULL){
            ListNode* kth = findKth(temp, k);
            if(!kth){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = kth->next;
            kth->next = NULL;
            reverse(temp);
            if(temp == head){
                head = kth;
            }else{
                prevNode->next = kth;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;
    }
};
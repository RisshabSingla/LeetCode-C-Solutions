/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

#include <set>

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // ListNode * itr = head;
        // set<ListNode*> mp;
        // while(itr!= NULL){
        //     if(mp.find(itr) != mp.end()){
        //         return true;
        //     }
        //     mp.insert(itr);
        //     itr = itr->next;
        // }
        // return false;

        
        if(head == NULL || head->next== NULL){
            return false;
        }
        ListNode * slow = head;
        ListNode * fast = head->next;
        while(slow!= fast){
            if(fast == NULL || fast->next == NULL){
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;


    }
};





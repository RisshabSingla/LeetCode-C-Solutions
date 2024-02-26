/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, int> mp;
        ListNode* ptr = head;
        while(ptr!= NULL){
            if(mp.count(ptr)){
                return ptr;
            }
            mp[ptr] = 1;
            ptr = ptr->next;
        }
        return NULL;
    }
};
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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* prev = list1;
        ListNode* ptr = list1;
        int index = 0;
        for(index = 0; index<a-1;index++){
            ptr = ptr->next;
        }
        prev = ptr;
        ListNode* end = ptr;
        for(; index<=b; index++){
            ptr = ptr->next;
        }
        end = ptr;
        prev->next = list2;
        ListNode* ptr2 = list2;
        while(ptr2->next){
            ptr2 = ptr2->next;
        }
        ptr2->next = end;
        return list1;
    }
};
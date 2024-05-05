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
    void deleteNode(ListNode* node) {
        // Approach 1: Changing the values of nodes
        // ListNode* prev;
        // while(node->next!= NULL){
        //     node->val = node->next->val;
        //     prev = node;
        //     node = node->next;
        // }
        // prev->next = NULL;


        // Approach 2: Changing the next pointer
        node->val = node->next->val;
        node->next = node->next->next;
    }
};
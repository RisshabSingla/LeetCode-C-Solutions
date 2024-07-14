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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> mp;
        for(auto i: nums){
            mp[i]++;
        }
        ListNode* nHead = NULL;
        while(head && mp.count(head->val)){
            head = head->next;
        }
        if(!head){
            return NULL;
        }
        nHead = head;
        ListNode* prev= nHead;
        ListNode* ptr = nHead->next;
        while(ptr){
            if(!mp.count(ptr->val)){
                prev->next = ptr;
                prev = prev->next;
            }
            ptr = ptr->next;
        }
        prev->next = NULL;
        return nHead;
    }
};
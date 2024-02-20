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

class Compare {
public:
    bool operator()(ListNode* a, ListNode* b) { return a->val > b->val; }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;
        for (ListNode* i : lists) {
            // cout << i << " \n";
            if (i) {
                pq.push(i);
            }
        }

        ListNode* head = NULL;
        ListNode* tail = NULL;
        while (!pq.empty()) {
            ListNode* temp = pq.top();
            // cout<<temp<<" "<<temp->val<<"\n";
            pq.pop();
            if (temp && temp->next) {
                pq.push(temp->next);
            }
            if (head) {
                tail->next = temp;
                tail = tail->next;
            } else {
                head = temp;
                tail = temp;
            }
        }
        return head;
    }
};
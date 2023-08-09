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
    int gcd(int a, int b){
        if(b == 0){
            return a;
        }
        return gcd(b, a%b);
    }
    // void printList(ListNode* ptr){
    //     ListNode* p = ptr;
    //     cout<<"Printing the list: ";
    //     while(p){
    //         cout<<p->val<<" ";
    //         p = p->next;
    //     }
    //     cout<<endl;
    // }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        
        bool valid = true;
        ListNode* first = head;
        ListNode* second = head->next;
        while(second){
            int val = gcd(first->val, second->val);
            ListNode* n = new ListNode(val);
            first->next = n;
            n->next =second;
            // printList(first);
            first = second;
            second = second->next;
        }
        return head;
    }
};
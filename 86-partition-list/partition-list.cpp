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
    // void printList(ListNode* head){
    //     ListNode* ptr = head;
    //     while(ptr!= NULL){
    //         cout<<ptr->val<<" ";
    //         ptr = ptr->next;
    //     }
    //     cout<<endl;
    // }
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = NULL;
        ListNode* more = NULL;
        ListNode* ptr = head;
        ListNode* hl = NULL;
        ListNode* hm = NULL;
        if(!head || !head->next){
            // length is zero or one
            return head;
        }

        while(ptr != NULL){
            if(ptr->val < x){
                if(!less){
                    // cout<<"Inside first less"<<endl;
                    less = ptr;
                    hl = ptr;
                    ptr = ptr->next;
                    hl->next = NULL;
                }else{
                    // cout<<"Inside second less"<<endl;
                    less->next = ptr;
                    less = less->next;
                    ptr = ptr->next;
                    less->next = NULL;
                }
            }else{
                if(!more){
                    // cout<<"Inside first more"<<endl;
                    more = ptr;
                    hm = ptr;
                    ptr = ptr->next;
                    hm->next = NULL;
                }else{
                    // cout<<"Inside second more"<<endl;
                    more->next = ptr;
                    more = more->next;
                    ptr = ptr->next;
                    more->next = NULL;
                }
            }
            // cout<<"Ptr is: "<<ptr<<endl;
        }
        // cout<<"Outside"<<endl;
        if(!less){
            return hm;
        }
        // cout<<"Less is: "<<less<<endl;
        // cout<<"More is: "<<more<<endl;
        // cout<<"hl is: "<<hl<<endl;
        // cout<<"hm is: "<<hm<<endl;
        less->next = hm;
        // printList(hl);
        return hl;
    }
};
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
    void reorderList(ListNode* head) {
        ListNode *slow =head;
        ListNode *fast=head;
        while(!head || !head->next){
            return;
        }
        while(fast->next && fast->next->next){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode *curr = slow->next;
        slow->next = NULL;
        ListNode *prev =NULL;
        while(curr){
            ListNode *next = curr->next;
            curr->next = prev;
            prev =curr;
            curr =next;
        }
        ListNode *p1=head;
        curr = prev;
        while(curr){
            ListNode *temp1 = p1->next;
            ListNode *temp2 = curr->next;

            p1->next = curr;
            curr->next = temp1;
            p1=temp1;
            curr=temp2; 
        }
    }
};
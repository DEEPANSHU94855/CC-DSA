// class Solution {
// public:
//     ListNode* oddEvenList(ListNode* head) {
//         ListNode* oddDummy = new ListNode(0);
//         ListNode* evenDummy = new ListNode(0);

//         ListNode* oddTail = oddDummy;
//         ListNode* evenTail = evenDummy;

//         ListNode* temp = head;
//         int position = 1;

//         while (temp != nullptr) {
//             ListNode* node = new ListNode(temp->val);

//             if (position % 2 == 1) {
//                 oddTail->next = node;
//                 oddTail = oddTail->next;
//             } else {
//                 evenTail->next = node;
//                 evenTail = evenTail->next;
//             }

//             temp = temp->next;
//             position++;
//         }

//         oddTail->next = evenDummy->next;

//         return oddDummy->next;
//     }
// };



class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;

        while (even != nullptr && even->next != nullptr) {
            odd->next = even->next;
            odd = odd->next;

            even->next = odd->next;
            even = even->next;
        }

        odd->next = evenHead;

        return head;
    }
};
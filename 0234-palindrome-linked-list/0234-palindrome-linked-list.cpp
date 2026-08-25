// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> values;

//         while (head != nullptr) {
//             values.push_back(head->val);
//             head = head->next;
//         }

//         int left = 0;
//         int right = values.size() - 1;

//         while (left < right) {
//             if (values[left] != values[right]) {
//                 return false;
//             }

//             left++;
//             right--;
//         }

//         return true;
//     }
// };

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = nullptr;

        while (head != nullptr) {
            ListNode* nextNode = head->next;
            head->next = prev;
            prev = head;
            head = nextNode;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        if (fast != nullptr) {
            slow = slow->next;
        }

        ListNode* second = reverse(slow);
        ListNode* first = head;

        while (second != nullptr) {
            if (first->val != second->val) {
                return false;
            }

            first = first->next;
            second = second->next;
        }

        return true;
    }
};
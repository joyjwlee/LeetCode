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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // get height of the list
        int h = 0;
        ListNode *temp = head;
        while (temp != NULL) {
            h++;
            temp = temp->next;
        }

        // edge case
        if (n == h)
            return head->next;

        // otherwise iterate through
        int idx = 0;
        temp = head;
        while (temp != NULL) {
            // if we reach where we need to be, remove
            if (idx == h - n - 1) {
                ListNode *rem = temp->next->next;
                temp->next = rem;
                break;
            }
            idx++;
            temp = temp->next;
        }
        return head;
    }
};
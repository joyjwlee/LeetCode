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
    ListNode *removeElements(ListNode *head, int val) {
        // edge
        if (head == NULL)
            return NULL;

        // iterate through and remove any with val
        ListNode *curr = new ListNode();
        curr->next = head;
        head = curr;
        while (curr->next != NULL) {
            // if at val, skip
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            }
            // otherwise iterate
            else {
                curr = curr->next;
            }
        }
        return head->next;
    }
};
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
    ListNode *deleteDuplicates(ListNode *head) {
        // create temp
        ListNode *temp = head;

        // edge cases
        if (temp == NULL)
            return NULL;
        if (temp->next == NULL)
            return head;

        // loop through, skip duplicates
        while (temp->next != NULL) {
            // if this and next value is same
            if (temp->val == temp->next->val)
                temp->next = temp->next->next;
            // otherwise move on
            else
                temp = temp->next;
        }

        // return once duplicates are removed
        return head;
    }
};
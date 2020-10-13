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
    // helper method to merge
    ListNode *merge(ListNode *one, ListNode *two) {
        // create current and temp
        ListNode *curr = new ListNode(0);
        ListNode *temp = curr;

        // merge them together
        while (one != NULL && two != NULL) {
            // put 1 first
            if (one->val < two->val) {
                curr->next = one;
                one = one->next;
            }
            // otherwise put 2
            else {
                curr->next = two;
                two = two->next;
            }
            curr = curr->next;
        }

        // any remaining and return
        if (one != NULL)
            curr->next = one;
        if (two != NULL)
            curr->next = two;
        return temp->next;
    }

    // merge sort
    ListNode *sortList(ListNode *head) {
        // edge case: 0 or 1 node
        if (head == NULL || head->next == NULL)
            return head;

        // slow and fast
        ListNode *slow = head;
        ListNode *fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // divide into first and second half, recurse through
        fast = slow->next;
        slow->next = NULL;
        return merge(sortList(head), sortList(fast));
    }
};
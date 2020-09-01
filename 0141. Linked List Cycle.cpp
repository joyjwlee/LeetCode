/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
  public:
    bool hasCycle(ListNode *head) {
        // 2 pointer solution: slow and fast
        // slow iterates 1, fast iterates 2
        ListNode *slow = head, *fast = head;
        while (fast != NULL) {
            // update both pointers
            slow = slow->next;
            if (fast->next != NULL)
                fast = fast->next->next;
            else
                return false;
            // if they are same, there is a loop
            if (slow == fast)
                return true;
        }

        // if while loop breaks, no loop
        return false;
    }
};
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
    ListNode *rotateRight(ListNode *head, int k) {
        // empty
        if (!head)
            return head;

        // get length and take mod for k
        ListNode *itr = head;
        int len = 0, pos = 0;
        while (itr) {
            len++;
            itr = itr->next;
        }
        k %= len;

        // if no rotations needed
        if (!k)
            return head;

        // get to element before Kth
        itr = head;
        while (pos < len - (k + 1)) {
            itr = itr->next;
            pos++;
        }

        // create answer, move rest to back
        ListNode *ans = itr->next;
        // create before Kth as null
        itr->next = NULL;
        ListNode *rest = ans;
        while (rest->next)
            rest = rest->next;
        rest->next = head;

        return ans;
    }
};
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
    ListNode *reverseList(ListNode *head) {
        // edge
        if (head == NULL)
            return NULL;

        // iterate and add to stack
        stack<int> nums;
        while (head != NULL) {
            nums.push(head->val);
            head = head->next;
        }

        // reverse order and return
        ListNode *temp = new ListNode(nums.top());
        head = temp;
        while (!nums.empty()) {
            temp->next = new ListNode(nums.top());
            temp = temp->next;
            nums.pop();
        }
        return head->next;
    }
};
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
    ListNode *swapNodes(ListNode *head, int k) {
        // convert linked list into vector
        vector<int> vals;
        while (head != NULL) {
            vals.push_back(head->val);
            head = head->next;
        }

        // swap the values
        swap(vals[k - 1], vals[vals.size() - k]);

        // convert back into linked list
        ListNode *curr = new ListNode();
        for (int i = vals.size() - 1; i >= 0; i--) {
            curr->val = vals[i];
            ListNode *temp = new ListNode();
            temp->next = curr;
            curr = temp;
        }
        return curr->next;
    }
};
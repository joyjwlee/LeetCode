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
    // helper to insert
    void insert_node(ListNode *&curr, int val) {
        // if null
        if (curr == NULL) {
            curr = new ListNode(val);
            return;
        }

        // otherwise iterate thru and add
        ListNode *temp = curr;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(val);
        return;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // edge cases
        if (!l1)
            return l2;
        if (!l2)
            return l1;
        // now go through both
        ListNode *ans = NULL;
        int carry = 0;
        while (l1 && l2) {
            int dig = carry + l1->val + l2->val;
            carry = dig / 10;
            insert_node(ans, dig % 10);
            l1 = l1->next;
            l2 = l2->next;
        }
        // go through each individually
        while (l1) {
            int dig = carry + l1->val;
            carry = dig / 10;
            insert_node(ans, dig % 10);
            l1 = l1->next;
        }
        while (l2) {
            int dig = carry + l2->val;
            carry = dig / 10;
            insert_node(ans, dig % 10);
            l2 = l2->next;
        }
        if (carry)
            insert_node(ans, carry);
        return ans;
    }
};

// this method caused overflow
/*
class Solution {
  public:
    // linked list to int, recursively
    int getVal(ListNode *ln) {
        // if null, return 0
        if (!ln)
            return 0;
        return ln->val + 10 * getVal(ln->next);
    }

    // helper to insert
    void insert_node(ListNode *&curr, int val) {
        // if null
        if (curr == NULL) {
            curr = new ListNode(val);
            return;
        }

        // otherwise iterate thru and add
        ListNode *temp = curr;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = new ListNode(val);
        return;
    }

    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        // get sum
        int sum = getVal(l1) + getVal(l2);
        // edge
        if (sum == 0)
            return new ListNode(0);
        // put sum to linked list, return ans
        ListNode *ans = NULL;
        while (sum != 0) {
            insert_node(ans, sum % 10);
            sum /= 10;
        }
        return ans;
    }
};
*/
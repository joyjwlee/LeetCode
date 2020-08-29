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

    // put list into vec
    void listToVec(vector<int> &v, ListNode *ln) {
        while (ln != NULL) {
            v.push_back(ln->val);
            ln = ln->next;
        }
    }

    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        // pull each one into a vector
        vector<int> v;
        listToVec(v, l1);
        listToVec(v, l2);
        // sort and create a new list
        sort(v.begin(), v.end());
        // put vector into new list
        ListNode *ans = new ListNode();
        for (int n : v)
            insert_node(ans, n);
        // next, since ans is set to zero
        return ans->next;
    }
};
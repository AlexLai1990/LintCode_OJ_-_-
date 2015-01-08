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
    /**
     * @param l1: the first list
     * @param l2: the second list
     * @return: the sum list of l1 and l2 
     */
    ListNode *addLists(ListNode *l1, ListNode *l2) { 
        if (l1 == NULL && l2 == NULL)
            return NULL;
        if (l1 == NULL)
            return l2;
        if (l2 == NULL)
            return l1;
        int carry = 0, sum = 0;
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        while (l1 != NULL && l2 != NULL) {
            sum = carry + l1->val + l2->val;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode (sum);
            l1 = l1->next;
            l2 = l2->next;
            curr = curr->next;
        }
        while (l1 != NULL) {
            sum = carry + l1->val;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode (sum);
            l1 = l1->next;
            curr = curr->next;
        }
        while (l2 != NULL) {
            sum = carry + l2->val;
            carry = sum / 10;
            sum %= 10;
            curr->next = new ListNode (sum);
            l2 = l2->next;
            curr = curr->next;
        }
        if (carry != 0)
            curr->next = new ListNode (carry);
        return dummy.next;
    }
};

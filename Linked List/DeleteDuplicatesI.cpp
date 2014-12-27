/**
 * Definition of ListNode
 * class ListNode {
 * public:
 *     int val;
 *     ListNode *next;
 *     ListNode(int val) {
 *         this->val = val;
 *         this->next = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode *deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *curr = head->next, *prev = head;
        while (curr != NULL) {
            if (curr->val == prev->val) {
                prev->next = curr->next;
            }
            else {
                prev->next = curr;
                prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};

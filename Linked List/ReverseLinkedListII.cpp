/**
 * Definition of singly-linked-list:
 * 
     * class ListNode {
     * public:
     *     int val;
     *     ListNode *next;
     *     ListNode(int val) {
     *        this->val = val;
     *        this->next = NULL;
     *     }
     * }
 */
class Solution {
public:
    /**
     * @param head: The head of linked list.
     * @param m: The start position need to reverse.
     * @param n: The end position need to reverse.
     * @return: The new head of partial reversed linked list.
     */
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        if (head == NULL)
            return NULL;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *curr = &dummy;
        for (int count = m; count > 1; count--) {
            curr = curr->next;
        }
        ListNode *prev = curr, *move = NULL, *next = NULL; 
        curr = curr->next;
        for (int count = 1; count <= n - m; count++) { 
            move = curr->next;
            next = move->next;
            
            move->next = prev->next;
            prev->next = move;
            curr->next = next; 
        }
        return dummy.next;
    }
};


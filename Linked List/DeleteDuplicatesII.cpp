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
class Solution{
public:
    /**
     * @param head: The first node of linked list.
     * @return: head node
     */
    ListNode * deleteDuplicates(ListNode *head) {
        // write your code here
        if (head == NULL)
            return NULL;
        ListNode dummy(-1);  
        ListNode *end = &dummy;
        ListNode *curr = head;
        while (curr != NULL) {
            if (curr->next != NULL && curr->val == curr->next->val) {
                // skip the same value node
                int curr_val = curr->val;
                curr = curr->next;
                while (curr != NULL && curr_val == curr->val) {
                    ListNode * m_del = curr;
                    curr = curr->next;
                    delete m_del;
                }
            }
            else {
                end->next = curr;
                end = end->next;
                curr = curr->next;
            } 
        }
        end->next = NULL;
        return dummy.next;
    }
};

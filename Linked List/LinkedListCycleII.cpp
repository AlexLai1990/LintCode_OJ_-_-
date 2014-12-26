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
     * @return: The node where the cycle begins. 
     *           if there is no cycle, return null
     */
    ListNode *detectCycle(ListNode *head) {
        // write your code here
        if (head == NULL)
            return NULL;
        ListNode *slow_ptr = head;
        ListNode *fast_ptr = head;
        while (fast_ptr != NULL && fast_ptr->next != NULL) {
            slow_ptr = slow_ptr->next;
            fast_ptr = fast_ptr->next->next;
            if (slow_ptr == fast_ptr) {
                fast_ptr = head;
                while (slow_ptr != fast_ptr && slow_ptr != NULL && fast_ptr != NULL) {
                    slow_ptr = slow_ptr->next;
                    fast_ptr = fast_ptr->next;
                } 
                return slow_ptr;
            }
        }  
        return NULL;
    }
};




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
     * @param x: an integer
     * @return: a ListNode 
     */
    ListNode *partition(ListNode *head, int x) {
        // write your code here
        if (head == NULL)
            return NULL;
        ListNode dummy1(-1);
        ListNode dummy2(-1);
        ListNode *small = &dummy1;
        ListNode *large = &dummy2; 
        while (head != NULL) {
            if (head->val < x) {
                small->next = head;
                small = small->next;
            }
            else {
                large->next = head;
                large = large->next;
            }
            head = head->next;
        }
        small->next = dummy2.next; 
        large->next = NULL;
        return dummy1.next;
    }
};




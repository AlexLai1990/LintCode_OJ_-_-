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
     * @return: void
     */
    void reorderList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
            return;
        ListNode *m_middle = findMiddle(head);
        ListNode *right_half = m_middle->next;
        m_middle->next = NULL;
        reverseList(right_half);
        mergeLists(head, right_half);
        return;
    }
    
    void mergeLists(ListNode *&list1, ListNode *list2) {
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        while (list1 != NULL && list2 != NULL) { 
            curr->next = list1;
            curr = curr->next;
            list1 = list1->next;
            
            curr->next = list2;
            curr = curr->next; 
            list2 = list2->next;  
        }
        curr->next = list1 != NULL ? list1 : list2;
        list1 = dummy.next;
        return ;
    }
    
    void reverseList(ListNode *&head) { 
        ListNode *curr = head, *prev = NULL, *next = NULL;
        while (curr != NULL) {
             next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
        } 
        head = prev;
        return;
    }
    
    ListNode *findMiddle(ListNode *head) {
        if (head == NULL)
            return head;
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *slow = &dummy, *fast = &dummy;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
}; 

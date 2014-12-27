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
     * @return: You should return the head of the sorted linked list,
                    using constant space complexity.
     */
    ListNode *sortList(ListNode *head) {
        // write your code here
        if (head == NULL || head->next == NULL)
            return head; 
            
        ListNode dummy(-1); 
        dummy.next = head;
        ListNode *slow = &dummy;
        ListNode *fast = &dummy;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *left_end = slow;
        ListNode *right_start = slow->next;
        left_end->next = NULL;
        
        ListNode *left = sortList(head);
        ListNode *right = sortList(right_start);
        return mergeLists(left, right);
    } 
    
    ListNode *mergeLists(ListNode *list1, ListNode *list2) {
        ListNode dummy(-1);
        ListNode *curr = &dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val < list2->val) {
                curr->next = list1;
                list1 = list1->next;
            }
            else {
                curr->next = list2;
                list2 = list2->next;
            }
            curr = curr->next;
        }
        curr->next = list1 != NULL ? list1 : list2;
        return dummy.next;
    }
};




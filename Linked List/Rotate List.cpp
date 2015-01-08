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
     * @param head: the list
     * @param k: rotate to the right k places
     * @return: the list after rotation
     */
    ListNode *rotateRight(ListNode *head, int k) {
        if (k == 0 || head == NULL)
            return head;
        int len = getLenOfList(head);
        if (len == 1)
            return head;
        k %= len;
        k = len - k;
        ListNode *left_last = head;
        for (int i = 1; i < k; i++) {
            left_last = left_last->next;
        }
        ListNode *new_head = left_last->next;
        left_last->next = NULL;
        ListNode *new_end = new_head;
        while (new_end != NULL && new_end->next != NULL)
            new_end = new_end->next;
        new_end->next = head;
        return new_head;
    }
    
    int getLenOfList(ListNode *head) {
        int count = 0;
        while (head != NULL) {
            count++;
            head = head->next;
        }
        return count;
    }
};

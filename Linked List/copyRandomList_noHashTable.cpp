/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    /**
     * @param head: The head of linked list with a random pointer.
     * @return: A new head of a deep copy of the list.
     */
    RandomListNode *copyRandomList(RandomListNode *head) {
        // write your code here  
        if (head == NULL)
            return NULL;
        RandomListNode *curr = head, *next;
        while (curr != NULL) {
            next = curr->next;
            RandomListNode *new_node = new RandomListNode(curr->label);
            curr->next = new_node;
            new_node->next = next;
            curr = next;
        }
        // set random ptr
        curr = head;
        RandomListNode *curr_copy = NULL;
        while (curr != NULL && curr->next != NULL) {
            if (curr->random != NULL) {
                curr_copy = curr->next;
                curr_copy->random = curr->random->next;
            }
            curr = curr->next->next;
        }
        // cut the original ptr
        RandomListNode dummy(-1);
        RandomListNode *m_new_head = &dummy;
        curr = head;
        while (curr != NULL) {
            curr_copy = curr->next;
            m_new_head->next = curr_copy;
            m_new_head = m_new_head->next;
            curr = curr_copy->next;
        }
        return dummy.next;
    }
};

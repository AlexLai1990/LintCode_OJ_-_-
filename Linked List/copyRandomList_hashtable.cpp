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
        unordered_map<RandomListNode *, RandomListNode *> m_dict;
        RandomListNode dummy(-1);
        RandomListNode *m_new_head = &dummy;
        RandomListNode *curr = head;
        while (curr != NULL) {
            if (m_dict.find(curr) == m_dict.end()) {
                RandomListNode *new_node = new RandomListNode(curr->label); 
                m_dict[curr] = new_node;
                m_new_head->next = new_node;
                m_new_head = m_new_head->next;
                curr = curr->next;
            }
            else 
                break;
        }
        curr = head;
        while (curr != NULL) {
            if (curr->random != NULL) {
                m_dict[curr]->random = m_dict[curr->random];    
            }
            curr = curr->next;
        }
        return dummy.next;
    }
};

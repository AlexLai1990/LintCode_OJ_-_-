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
class NodeCompare {
public:
    bool operator() (ListNode *node1, ListNode *node2) {
        if (node1->val > node2->val)
            return true;
        else
            return false;
    } 
}; 
 
class Solution {
public:
    /**
     * @param lists: a list of ListNode
     * @return: The head of one sorted list.
     */
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        // write your code here
        int k = lists.size();
        if (k < 1)
            return NULL;
        priority_queue<ListNode*, vector<ListNode*>, NodeCompare> m_pq;
        for (int i = 0; i < lists.size(); i++) {
            if (lists[i] != NULL)
                m_pq.push(lists[i]);
        }
        ListNode dummy(-1);
        ListNode *curr = &dummy, *min_node = NULL;
        while (m_pq.size() > 0) {
            min_node = m_pq.top();
            m_pq.pop();
            curr->next = min_node;
            curr = curr->next;
            min_node = min_node->next;
            if (min_node != NULL)
                m_pq.push(min_node);
        }
        return dummy.next;
    }
};




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
     * @param hashTable: A list of The first node of linked list
     * @return: A list of The first node of linked list which have twice size
     */    
    vector<ListNode*> rehashing(vector<ListNode*> hashTable) {
        int capacity = hashTable.size();
        int node_counts = 0;
        ListNode *curr_head = NULL, *next_head = NULL;
        for (int i = 0; i < hashTable.size(); i++) {
            curr_head = hashTable[i];
            while (curr_head != NULL) {
                node_counts++;
                curr_head = curr_head->next;
            }
        }
        if (capacity == 0 || node_counts < capacity / 10)
            return hashTable;
        int new_capacity = capacity * 2;
        vector<ListNode *> m_res(new_capacity, NULL);
        int new_index = 0;
        for (int i = 0; i < capacity; i++) {
            curr_head = hashTable[i];
            while (curr_head != NULL) {
                next_head = curr_head->next;
                new_index = (curr_head->val + new_capacity) % new_capacity;
                if (m_res[new_index] == NULL) {
                    m_res[new_index] = curr_head;
                }
                else {
                    ListNode *temp_head = m_res[new_index];
                    while (temp_head->next != NULL) 
                        temp_head = temp_head->next;
                    temp_head->next = curr_head;
                }
                curr_head->next = NULL;
                curr_head = next_head;
            }
        }
        return m_res;
    }
};


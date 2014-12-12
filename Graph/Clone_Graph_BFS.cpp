/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param node: A undirected graph node
     * @return: A undirected graph node
     */
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // write your code here
        if (node == NULL)
            return NULL;
        UndirectedGraphNode *m_new_root = new UndirectedGraphNode(node->label);
        queue<UndirectedGraphNode *> m_queue;
        m_queue.push(node);
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m_dict;
        m_dict[node] = m_new_root;
        
        while (!m_queue.empty()) {
            UndirectedGraphNode *curr = m_queue.front();
            m_queue.pop();
            for (int i = 0; i < curr->neighbors.size(); i++) {
                if (m_dict.find(curr->neighbors[i]) != m_dict.end()) {
                    m_dict[curr]->neighbors.push_back(m_dict[curr->neighbors[i]]);
                }
                else {
                    UndirectedGraphNode *new_neighbor = new UndirectedGraphNode(curr->neighbors[i]->label);
                    m_dict[curr->neighbors[i]] = new_neighbor;
                    m_dict[curr]->neighbors.push_back(new_neighbor);
                    m_queue.push(curr->neighbors[i]);
                }
            }
        }
        return m_new_root;
    }
};

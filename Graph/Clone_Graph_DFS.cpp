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
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> m_dict;
        return cloneGraphHelper(node, m_dict);
    }
    
    // return the copy node for current node
    UndirectedGraphNode *cloneGraphHelper(UndirectedGraphNode *node, 
    unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> &m_dict) {
        if (m_dict.find(node) != m_dict.end())
            return m_dict[node];
        else {
            UndirectedGraphNode * m_new = new UndirectedGraphNode(node->label);
            m_dict[node] = m_new;
            for (int i = 0; i < node->neighbors.size(); i++) {
                UndirectedGraphNode *curr_child = node->neighbors[i];
                m_dict[node]->neighbors.push_back(cloneGraphHelper(curr_child, m_dict));
            }
            return m_new;
        } 
    }
};

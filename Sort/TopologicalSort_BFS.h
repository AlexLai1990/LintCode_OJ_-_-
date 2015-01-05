/**
 * Definition for Directed graph.
 * struct DirectedGraphNode {
 *     int label;
 *     vector<DirectedGraphNode *> neighbors;
 *     DirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    /**
     * @param graph: A list of Directed graph node
     * @return: Any topological order for the given graph.
     */
    vector<DirectedGraphNode*> topSort(vector<DirectedGraphNode*> graph) {
        vector<DirectedGraphNode*> m_res;
        if (graph.size() < 1)
            return m_res;
        unordered_map<DirectedGraphNode*, int> visited;
        queue<DirectedGraphNode*> m_queue;
        for (auto vertex: graph) {
            for (auto neighbor : vertex->neighbors) {
                visited[neighbor]++;
            }
        }
        // push in-degree == 0 in queue
    	for (auto vertex : graph) { 
    		if (visited.find(vertex) == visited.end())
    			m_queue.push(vertex);
    	}
        DirectedGraphNode* curr = NULL;
        while (!m_queue.empty()) {
            curr = m_queue.front();
            m_queue.pop();
            m_res.push_back(curr);
            for (auto nei : curr->neighbors) {
                if (--visited[nei] == 0) {
                    m_queue.push(nei);
                }
            }
        }
        return m_res;
    }
};

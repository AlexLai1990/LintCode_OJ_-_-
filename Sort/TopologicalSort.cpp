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
        unordered_map<DirectedGraphNode*, bool> visited;
        stack<DirectedGraphNode*> m_stack;
        for (auto item : graph) {
            visited[item] = false;
        }
        for (int i = 0; i < graph.size(); i++) {
            if (visited[graph[i]] == false) {
                topSortHelper(graph[i], visited, m_stack);
            }
        }
        while (!m_stack.empty()) {
            m_res.push_back(m_stack.top());
            m_stack.pop();
        }
        return m_res;
    }
    
    void topSortHelper(DirectedGraphNode* curr, 
        unordered_map<DirectedGraphNode*, bool> &visited, stack<DirectedGraphNode*> &m_stack) {
        visited[curr] = true;
        for (int i = 0; i < curr->neighbors.size(); i++) {
            if (visited[curr->neighbors[i]] == false) {
                topSortHelper(curr->neighbors[i], visited, m_stack);
            }
        }
        m_stack.push(curr);
        return;
    }
};

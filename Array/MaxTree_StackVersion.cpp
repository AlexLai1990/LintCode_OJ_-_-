/**
 * Definition of TreeNode:
 * class TreeNode {
 * public:
 *     int val;
 *     TreeNode *left, *right;
 *     TreeNode(int val) {
 *         this->val = val;
 *         this->left = this->right = NULL;
 *     }
 * }
 */
class Solution {
public:
    /**
     * @param A: Given an integer array with no duplicates.
     * @return: The root of max tree.
     */
    TreeNode* maxTree(vector<int> A) {
        // write your code here
        if (A.size() < 1)
            return NULL; 
        vector<TreeNode *> m_nodes(A.size(), NULL);
        for (int i = 0; i < A.size(); i++) {
            TreeNode *new_add = new TreeNode(A[i]);
            m_nodes[i] = new_add;
        } 
        vector<TreeNode *> m_left_max(A.size(), NULL);
        stack<TreeNode *> m_stack_left;
        for (int i = 0; i < A.size(); i++) {
            while (!m_stack_left.empty() && m_stack_left.top()->val < A[i]) {
                m_stack_left.pop();
            }
            m_left_max[i] = m_stack_left.empty() ? NULL : m_stack_left.top();
            m_stack_left.push(m_nodes[i]);
        }
        
        stack<TreeNode *> m_stack_right;
        TreeNode *m_root = NULL;
        for (int i = A.size() - 1; i >= 0; i--) {
            while (!m_stack_right.empty() && m_stack_right.top()->val < A[i]) {
                m_stack_right.pop();
            }
            TreeNode *right_max = m_stack_right.empty() ? NULL : m_stack_right.top();
            m_stack_right.push(m_nodes[i]);
            
            // construct tree
            TreeNode *parent = NULL;
            if (m_left_max[i] == NULL && right_max == NULL) {
                m_root = m_nodes[i];
                continue;
            }
            else if (right_max == NULL || 
                    (m_left_max[i] != NULL && right_max->val > m_left_max[i]->val)) {
                parent = m_left_max[i];
                parent->right = m_nodes[i];
            }
            else if (m_left_max[i] == NULL || 
                    (right_max != NULL && right_max->val < m_left_max[i]->val)) {
                parent = right_max;
                parent->left = m_nodes[i];
            } 
        } 
        return m_root;
    }  
};

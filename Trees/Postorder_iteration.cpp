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
    /**
     * @param root: The root of binary tree.
     * @return: Postorder in vector which contains node values.
     */
public:
    vector<int> postorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> m_ret;
        if (root == NULL)
            return m_ret;
        stack<TreeNode *> m_stack;
        m_stack.push(root);
        TreeNode *curr = NULL, *prev = NULL;
        while (!m_stack.empty()) {
            curr = m_stack.top();
            if (!prev || curr == prev->left || curr == prev->right) {
                if (curr->left != NULL)
                    m_stack.push(curr->left);
                else if (curr->right != NULL)
                    m_stack.push(curr->right);
                else {
                    m_ret.push_back(curr->val);
                    m_stack.pop();
                }    
            }
            else if (prev == curr->left) { 
                if (curr->right != NULL) {
                    m_stack.push(curr->right);
                }
                else {
                    m_ret.push_back(curr->val);
                    m_stack.pop();
                }
            }
            else {
                m_ret.push_back(curr->val);
                m_stack.pop();  
            }
            prev = curr;
        }
        
        return m_ret;
    }
};

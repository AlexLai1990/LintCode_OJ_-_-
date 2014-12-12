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
     * @return: Inorder in vector which contains node values.
     */
public:
    vector<int> inorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> m_ret;
        if (root == NULL)
            return m_ret;
        stack<TreeNode *> m_stack;
        TreeNode *curr = root;
        while (true) {
            // update the curr node, if it has left node
            while (curr != NULL) {
                m_stack.push(curr);
                curr = curr->left;
            }
            if (m_stack.size() < 1)
                break;
            curr = m_stack.top();
            m_stack.pop();
            m_ret.push_back(curr->val);
            
            curr = curr->right;
        }
        
        return m_ret;
    }
};

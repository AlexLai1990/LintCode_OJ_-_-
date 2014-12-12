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
     * @param root: The root of binary tree.
     * @return: Preorder in vector which contains node values.
     */
    vector<int> preorderTraversal(TreeNode *root) {
        // write your code here
        vector<int> m_ret;
        if (root == NULL)
            return m_ret;
        stack<TreeNode *> m_stack;
        m_stack.push(root);
        TreeNode *curr = NULL;
        while (!m_stack.empty()) {
            curr = m_stack.top();
            m_stack.pop();
            m_ret.push_back(curr->val);
            if (curr->right != NULL)
                m_stack.push(curr->right);
            if (curr->left != NULL)
                m_stack.push(curr->left);
        }
        return m_ret;
    }
};


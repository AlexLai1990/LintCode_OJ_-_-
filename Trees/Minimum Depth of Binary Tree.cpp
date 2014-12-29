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
     * @return: An integer
     */
    int minDepth(TreeNode *root) {
        // write your code here
        if (root == NULL)
            return 0;
        queue<TreeNode *> m_queue;
        m_queue.push(root);
        TreeNode *curr = NULL;
        int height = 0;
        while (m_queue.size() > 0) {
            int size = m_queue.size(); 
            height++;
            for (int i = 0; i < size; i++) {
                curr = m_queue.front();
                m_queue.pop();
                if (curr->left == NULL && curr->right == NULL)
                    return height;
                if (curr->left != NULL)
                    m_queue.push(curr->left);
                if (curr->right != NULL)
                    m_queue.push(curr->right);
            }
        }
        return height;
    }
};

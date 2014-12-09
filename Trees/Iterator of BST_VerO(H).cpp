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
 * Example of iterate a tree:
 * Solution iterator = Solution(root);
 * while (iterator.hasNext()) {
 *    TreeNode * node = iterator.next();
 *    do something for node
 */
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        if (root == NULL)
            return;
        m_curr = NULL;
        m_stack.push(root);
        findleftMost(root);  
        return;
    }

    //@return: True if there has next node, or false
    bool hasNext() {
        // write your code here
        if (m_stack.size() < 1) {
            return false;
        }
        else {
            return true;
        }
    }
    
    //@return: return next node
    TreeNode* next() {
        // write your code here
        if (m_stack.size() < 1)
            return NULL;
        else {
            m_curr = m_stack.top();
            m_stack.pop();   
            if (m_curr->right != NULL) {
                m_stack.push(m_curr->right);
                findleftMost(m_curr->right);
            }
            return m_curr;
        }
    }
    
    void findleftMost(TreeNode *curr) {
        if (curr == NULL)
            return ;
        while (curr->left != NULL) {
            m_stack.push(curr->left);
            curr = curr->left;
        } 
        return ;
    }
    
private:
    TreeNode *m_curr;
    stack<TreeNode *> m_stack;
};

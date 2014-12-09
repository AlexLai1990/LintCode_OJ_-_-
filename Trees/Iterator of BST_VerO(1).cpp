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
 
 // reference: http://www.geeksforgeeks.org/inorder-successor-in-binary-search-tree/
 
class Solution {
public:
    //@param root: The root of binary tree.
    Solution(TreeNode *root) {
        // write your code here
        m_curr = NULL;
		m_right_most = NULL; 
		if (root == NULL)
			return;
		m_root = root;
		m_curr = findLeftMost(root);
		m_right_most = findRightMost(root);
    }

    //@return: True if there has next node, or false
    bool hasNext() { 
        if (m_curr != NULL && m_right_most != NULL &&
            m_curr->val <= m_right_most->val)
            return true;
        else 
            return false;
    }
    
    //@return: return next node
    TreeNode* next() {
        TreeNode *m_ret = m_curr;
        m_curr = updateNext();
        return m_ret;
    }
    
    TreeNode *updateNext(){ 
        if (!hasNext())
            return NULL;
        if (m_curr->right != NULL) {
            return findLeftMost(m_curr->right);
        }
        else {
            int cur_val = m_curr->val;
            TreeNode *temp_root = m_root;
            TreeNode *m_parent = NULL;
            while (temp_root != NULL) {
                if (cur_val == temp_root->val) {
                    m_curr = m_parent;
                    break;
                }
                else if (cur_val < temp_root->val) {
                    m_parent = temp_root;
                    temp_root = temp_root->left;
                }
                else {
                    temp_root = temp_root->right;
                }
            }
            return m_parent;
        }
    }

    TreeNode *findLeftMost(TreeNode *cur) {
        if (cur == NULL)
            return NULL;
        else {
            while (cur->left != NULL) {
                cur = cur->left;
            }
            return cur;
        }
    }
    
    TreeNode *findRightMost(TreeNode *cur) {
        if (cur == NULL)
            return NULL;
        else {
            while (cur->right != NULL) {
                cur = cur->right;
            }
            return cur;
        }
    }
    
private:
    TreeNode *m_root;
    TreeNode *m_curr;
    TreeNode *m_right_most;
};
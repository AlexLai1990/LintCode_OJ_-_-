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
     * @return: True if this Binary tree is Balanced, or false.
     */
    bool isBalanced(TreeNode *root) {
        // write your code here
        return isBalancedHelper(root) == -1 ? false : true;
    }
    
    int isBalancedHelper(TreeNode *curr) {
        if (curr == NULL)
            return 0;
        int left_height = isBalancedHelper(curr->left);
        int right_height = isBalancedHelper(curr->right);
        if (left_height == -1 || right_height == -1 || abs(left_height - right_height) > 1)
            return -1;
        return max(left_height, right_height) + 1;
    }
    
};

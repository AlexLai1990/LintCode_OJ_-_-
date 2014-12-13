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
    int maxPathSum(TreeNode *root) {
        // write your code here
        max_sum = INT_MIN;
        maxPathSumHelper(root);
        return max_sum;
    }
    
    int maxPathSumHelper(TreeNode *root) {
        if (root == NULL)
            return 0;
        int left_subtree = maxPathSumHelper(root->left);
        int right_subtree = maxPathSumHelper(root->right);
        int all_sum = root->val;
        all_sum = left_subtree > 0 ? all_sum + left_subtree : all_sum;
        all_sum = right_subtree > 0 ? all_sum + right_subtree : all_sum;
        if (all_sum > max_sum)
            max_sum = all_sum;
        return max(left_subtree, right_subtree) > 0 ? root->val + max(left_subtree, right_subtree) : root->val;
    }
    
private:
    int max_sum;
    
};

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
     * @paramn n: An integer
     * @return: A list of root
     */
    vector<TreeNode *> generateTrees(int n) {
        return generateTreesHelper(1, n);
    }
    
    vector<TreeNode *> generateTreesHelper(int start, int end) {
        if (start > end) {
            vector<TreeNode *> res;
            res.push_back(NULL);
            return res;
        }
        vector<TreeNode *> m_res;
        for (int i = start; i <= end; i++) {
            vector<TreeNode *> m_left = generateTreesHelper(start, i - 1);
            vector<TreeNode *> m_right = generateTreesHelper(i + 1, end);
            for (int j = 0; j < m_left.size(); j++) {
                for (int k = 0; k < m_right.size(); k++) {
                    TreeNode *root = new TreeNode(i);
                    root->left = m_left[j];
                    root->right = m_right[k];
                    m_res.push_back(root);
                }
            } 
        }
        return m_res;
    }
};

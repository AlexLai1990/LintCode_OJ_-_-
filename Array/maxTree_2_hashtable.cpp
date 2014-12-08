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
        unordered_map<int, TreeNode*> m_dict;
        for (int i = 0; i < A.size(); i++) {
            TreeNode *new_add = new TreeNode(A[i]);
            m_dict[i] = new_add;
        }
        vector<int> m_parent(A.size(), -1);
        for (int i = 0; i < A.size(); i++) {
            m_parent[i] = (getParent(A, i));
        }
        // construct tree
        TreeNode *m_root = NULL;
        for (int i = 0; i < A.size(); i++) {
            int parent_index = m_parent[i];
            if (parent_index == -1) {
                m_root = m_dict[i];
                continue;
            }
            else if (parent_index < i){
                TreeNode *parent_node = m_dict[parent_index];
                TreeNode *curr_node = m_dict[i];
                parent_node->right = curr_node;
            } 
            else if (parent_index > i) { 
                TreeNode *parent_node = m_dict[parent_index];
                TreeNode *curr_node = m_dict[i];
                parent_node->left = curr_node;
            }
        }
        return m_root;
    } 
    
    int getParent(vector<int> &A, int curr) {
        int left_first_large = INT_MIN;
        int right_first_large = INT_MIN; 
        int left = curr - 1, right = curr + 1;
        while (left >= 0) {
            if (A[left] > A[curr]) {
                left_first_large = left;
                break;    
            }
            left--;
        }
        while (right <= A.size() - 1) {
            if (A[right] > A[curr]) {
                right_first_large = right;
                break;    
            }
            right++;
        }
        if (left < 0 && right == A.size())
            // current index is the max int the array
            return -1;
        else if (left_first_large != INT_MIN && right_first_large != INT_MIN)
            return A[left_first_large] < A[right_first_large] ? left_first_large: right_first_large;
        else if (left_first_large != INT_MIN)
            return left_first_large;
        else if (right_first_large != INT_MIN)
            return right_first_large;
    } 
};

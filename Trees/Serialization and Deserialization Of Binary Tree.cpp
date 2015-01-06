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
 
#include <sstream> 

class Solution {
public:
    /**
     * This method will be invoked first, you should design your own algorithm 
     * to serialize a binary tree which denote by a root node to a string which
     * can be easily deserialized by your own "deserialize" method later.
     */
    string serialize(TreeNode *root) {
        string m_res = "";
        if (root == NULL)
            return m_res;
        queue<TreeNode *> m_queue;
        m_queue.push(root);
        TreeNode *curr = NULL;
        while (!m_queue.empty()) {
            curr = m_queue.front();
            m_queue.pop();
            m_res += ' ';
            if (curr == NULL)
                m_res += '#';
            else {
                m_res += to_string(curr->val);
                m_queue.push(curr->left);
                m_queue.push(curr->right);
            }
        }
        m_res = m_res.substr(1);
        return m_res;
    }

    /**
     * This method will be invoked second, the argument data is what exactly
     * you serialized at method "serialize", that means the data is not given by
     * system, it's given by your own serialize method. So the format of data is
     * designed by yourself, and deserialize it here as you serialize it in 
     * "serialize" method.
     */
    TreeNode *deserialize(string data) { 
        if (data == "") {
            return NULL;
        }
        int root_val;
        istringstream ss(data);
        ss >> root_val;
        TreeNode *m_root = new TreeNode(root_val);
        queue<TreeNode *> m_queue;
        m_queue.push(m_root);
        TreeNode * curr = NULL;
        while (!m_queue.empty()) {
            curr = m_queue.front();
            m_queue.pop();
            string curr_str;
            ss >> curr_str;
            if (curr_str != "#") {
                curr->left = new TreeNode (getDigit(curr_str));
                m_queue.push(curr->left);
            }
            ss >> curr_str;
            if (curr_str != "#") {
                curr->right = new TreeNode (getDigit(curr_str));
                m_queue.push(curr->right);
            }
        }
        return m_root;
    }
    
    int getDigit(string input) {
        int m_ret;
        istringstream ss(input);
        ss >> m_ret;
        return m_ret;
    }
};

